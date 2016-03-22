/*
*	������������洢
*	ʵ�ֹ��ܣ�
*	���������������ֱ���
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;//ָ�����Һ��ӵ�ָ��
}BiTNode, *BiTree;//�ڵ����

int PrintElem(char e);
int CreateBiTree(BiTree &T);//���������ɹ�����1��ʧ�ܷ���-1
int PreOrderTraverse(BiTree &T, int(*visit)(char e));//�������
int InOrderTraverse(BiTree &T, int(*visit)(char e));//�������
int PostOrderTraverse(BiTree &T, int(*visit)(char e));//�������
int LevelOrderTraverse(BiTree &T, int(*visit)(char e));//�������
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
	//������
	
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
	//�ݹ����δ�ӡ�����Ľ��
	if (T) {//���ǿ���
		if (visit(T->data))//��ӡ��
			if (PreOrderTraverse(T->lchild, visit))//������
			if (PreOrderTraverse(T->rchild, visit))//������
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
	//�ݹ�ʵ���������
	if (T) {
		if (InOrderTraverse(T->lchild, visit))
			visit(T->data);
		if (InOrderTraverse(T->rchild, visit))
			return 1;
	}
	else
		return -1;
/*	ջ��ʵ�֣�
**	InitStack(S);//��ʼ��һ����ջ
**	Push(S,T);//����ѹ��ջ
**	while (ջ�ǿ�)
{ ����������������ѹ��ջ
	��ָ���ջ
	���ʽ�㣬�����Һ���ѹ��ջ
	�㷨6.2
}
*/
}

int PostOrderTraverse(BiTree &T, int(*visit)(char e))
{
	//����������ݹ��㷨ʵ��
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
	cout << "�������ݣ�@�������磺" << endl;
	cout << "1 @ @" << endl;
	cout << "***************************" << endl;
	BiTree mybt;
	CreateBiTree(mybt);
	if (!mybt)
		cout << "����" << endl;
	cout << "���������" << endl;
	PreOrderTraverse(mybt, PrintElem);
	cout <<"���������" <<endl;
	InOrderTraverse(mybt, PrintElem);
	cout << "���������" << endl;
	PostOrderTraverse(mybt, PrintElem);

	//cout << mybt->data << mybt->lchild->data << mybt->rchild->data << endl;
	system("pause");
}

/*	ѧϰ����
**	1.�ݹ鷽��
**	��ӽ�ԭʼ�㷨�����ÿ���̫����м����ݵĴ���ֻ��Ҫ����ԭ����
**	����Ч���ǲ��ߵģ�������ʱ��
**	���ϵ���������ӽ�ԭʼ���㷨���ȱ����������������ٱ���������
**	�����ݹ�Ľ��������л��ƻ�����̫�˽�
*/