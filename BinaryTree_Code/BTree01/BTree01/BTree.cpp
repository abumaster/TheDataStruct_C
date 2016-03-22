/*
*	二叉树的链表存储
*	实现功能：
*	构建二叉树，三种遍历
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;//指向左右孩子的指针
}BiTNode, *BiTree;//节点和树

int PrintElem(char e);
int CreateBiTree(BiTree &T);//创建树，成功返回1，失败返回-1
int PreOrderTraverse(BiTree &T, int(*visit)(char e));//先序遍历
int InOrderTraverse(BiTree &T, int(*visit)(char e));//中序遍历
int PostOrderTraverse(BiTree &T, int(*visit)(char e));//后序遍历
int LevelOrderTraverse(BiTree &T, int(*visit)(char e));//层序遍历
///////////////////////
int PrintElem(char e)
{
	cout << e << endl;
	//cout << "\t\t" << e << "\n ";
	//cout << "\t\t" << "/" << "\\" << endl;
	return 1;
}

int CreateBiTree(BiTree &T)
{
	//创建树
	
	char mint;
	cin >> mint;
	if (mint == '@') T = NULL;
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return -1;
		T->data = mint;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return 1;
}
int PreOrderTraverse(BiTree &T, int(*visit)(char e))
{
	//递归依次打印出树的结点
	if (T) {//不是空树
		if (visit(T->data))//打印根
			if (PreOrderTraverse(T->lchild, visit))//左子树
			if (PreOrderTraverse(T->rchild, visit))//右子树
				return 1;
			return -1;
			//PreOrderTraverse(T->lchild, visit);
		//PreOrderTraverse(T->rchild, visit);
		//else { return -1; }
		
	}
	else {
		return 1;
	}
}
int InOrderTraverse(BiTree &T, int(*visit)(char e))
{
	//递归实现中序遍历
	if (T) {
		if (InOrderTraverse(T->lchild, visit))
			visit(T->data);
		if (InOrderTraverse(T->rchild, visit))
			return 1;
	}
	else
		return -1;
/*	栈的实现：
**	InitStack(S);//初始化一个空栈
**	Push(S,T);//将根压入栈
**	while (栈非空)
{ 遍历左子树，依次压入栈
	空指针出栈
	访问结点，并把右孩子压入栈
	算法6.2
}
*/
}

int PostOrderTraverse(BiTree &T, int(*visit)(char e))
{
	//后序遍历，递归算法实现
	if (T) {
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T->data);

	}
	else
		return -1;
}

int main()
{
	cout << "输入数据，@空树，如：" << endl;
	cout << "1 @ @" << endl;
	cout << "***************************" << endl;
	BiTree mybt;
	CreateBiTree(mybt);
	if (!mybt)
		cout << "空树" << endl;
	cout << "先序遍历：" << endl;
	PreOrderTraverse(mybt, PrintElem);
	cout <<"中序遍历：" <<endl;
	InOrderTraverse(mybt, PrintElem);
	cout << "后序遍历：" << endl;
	PostOrderTraverse(mybt, PrintElem);

	//cout << mybt->data << mybt->lchild->data << mybt->rchild->data << endl;
	system("pause");
}

/*	学习感悟：
**	1.递归方法
**	最接近原始算法，不用考虑太多的中间数据的处理，只需要调用原函数
**	但是效率是不高的，层次深的时候
**	如上的中序遍历接近原始的算法，先遍历左子树，根，再遍历右子树
**	但，递归的结束和运行机制还不够太了解
*/