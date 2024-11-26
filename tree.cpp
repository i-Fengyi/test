#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;                       			//节点数据
	struct node *lchild, *rchild;         		//左、右孩子指针
}BSTree; 										//二叉树节点类型

void Preorder(BSTree *p)                     	//先序遍历二叉树
{
	if(p != NULL)
	{
		printf("%d\n", p->data);              	//访问根节点
		Preorder(p->lchild);                   	//先序遍历左子树
		Preorder(p->rchild);                    //先序遍历右子树
	}
	
	return ;
}

void Inorder(BSTree *p)                     	//中序遍历二叉树
{
	if(p != NULL)
	{
		Inorder(p->lchild);                     //中序遍历左子树
		printf("%d-%p\n", p->data, p);                  	//访问根节点
		Inorder(p->rchild);                     //中序遍历右子树
	}
}

void Postorder(BSTree *p)                   	//后序遍历二叉树
{
	if(p != NULL)
	{
		Postorder(p->lchild);                  	//后序遍历左子树
		Postorder(p->rchild);                  	//后序遍历右子树
		printf("%d\n", p->data);                   //访问根节点
	}
}

BSTree* createNode(int data) 					// 创建节点的函数
{
    BSTree* newNode;
    
    newNode = (BSTree *)malloc(sizeof(BSTree));
    if(newNode == NULL) 
	{
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
 
    return newNode;
} 
 

BSTree* insertBST(BSTree* root, int data) 		// 创建二叉树的函数
{
    if (root == NULL) 
	{
        root = createNode(data);
    } 
	else 
	{
        if (data < root->data) 
		{
            root->lchild = insertBST(root->lchild, data);
        } else 
		{
            root->rchild = insertBST(root->rchild, data);
        }
    }
 
    return root;
}

int Depth(BSTree *p)              		//后序遍历求二叉树的深度
{
	int ldepth, rdepth;
	
	if(p == NULL) 
		return 0;          				//树的深度为0
	else
	{
		ldepth = Depth(p->lchild);   		//递归调用求左子树高度
		rdepth = Depth(p->rchild);   		//递归调用求右子树高度
		if(ldepth > rdepth)
			return ldepth + 1;
		else
			return rdepth + 1;
	}
}

int CountNode(BSTree *bt) 
{
	int lNode, rNode;
	if(bt == NULL)
		return 0; 
		
	lNode = CountNode(bt->lchild);
	rNode = CountNode(bt->rchild);                   		

	return lNode + rNode + 1;
}

int Countleaf(BSTree *bt)        		//统计二叉树中叶子节点的个数
{
	int lleaf, rleaf;
	
	if(bt == NULL)
		return 0;                     		//空二叉树
		
	if( (bt->rchild == NULL) && (bt->lchild == NULL) )
		return 1;                     		//只有根节点
		
	lleaf = Countleaf(bt->lchild);
	rleaf = Countleaf(bt->rchild);                   		
	
	return lleaf + rleaf;
} 

BSTree* search(BSTree *p, int x)                     	//先序遍历二叉树
{
	BSTree* bt;

	if(p!=NULL)
	{
		if(p->data == x)
			return p;
		
		if(p->lchild != NULL)
		{	
			bt = search(p->lchild, x);                   	//先序遍历左子树
			if(bt != NULL)
				return bt;
		}
		if(p->rchild != NULL)
		{
			bt = search(p->rchild, x);
			if(bt != NULL)
				return bt;
		}
   }
   
   return NULL;
}

#if 0



void change(BSTree* tree)
{
	BSTree* tmp;
	BSTree* p = tree;
	
	if( (p->lchild == NULL) || (p->rchild == NULL) )
		return ;
	
	if( p->lchild->data > p->rchild->data)
	{
		tmp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = tmp;
	}
	
	change(p->lchild);
    change(p->rchild);	
}
#endif
int main(void)
{
   BSTree *root, *p;
   int i, sum, arr[] = {50, 30, 20, 10, 40, 70, 60, 80, 90};
   
   root = NULL;
 
    // 插入元素建立二叉搜索树
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        root = insertBST(root, arr[i]);        
    }
   
   printf("Preorder output bitree: \n");
   Preorder(root);                           	//先序遍历二叉树
   
   printf("Inorder output bitree: \n");   
   Inorder(root);
   
   printf("Postorder output bitree: \n");
   Postorder(root);  
   
   sum = Depth(root);
   printf("depth of bitree: %d\n", sum);
   
   sum = CountNode(root);
   printf("node count of bitree: %d\n", sum);
   
   sum = Countleaf(root);
   printf("node count of bitree: %d\n", sum);
   
	p = search(root, 60);
    printf("p : %p\t", p);//后序遍历二叉树

	return 0;
}
