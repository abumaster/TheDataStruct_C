#include <iostream>
using namespace std;

/*	ջ��˳��洢ʵ��
*	���ݽṹ P46 �㷨ʵ�� 
*	ʱ�䣺20160308
*/
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef struct {//����ջ�Ľṹ��ջ��ջ��ָ�룬ջ�Ĵ�С 
	int *base;
	int *top;
	int stacksize;
}SqStack;

//ջ�Ĳ�����������ʼ������ջ����ջ����ȡջ��Ԫ��
int InitStack(SqStack &S)
{
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base) {
		//cout<<"�ڴ�������"<<endl;
		return -1;
	}
	S.top=S.base;//
	S.stacksize = STACK_INIT_SIZE;
	return 1;
} 
int Push(SqStack &S, int e)
{
	//��Ԫ��eѹ��ջ���ɹ�����1��ʧ�ܷ���-1
	if ((S.top-S.base) >= S.stacksize) {//ջ���ӿռ�
		S.base =(int *)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(int));
		if (!S.base) return -1;//�洢����ʧ�ܣ��������˳�
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT; 
	} 
	*(S.top++) = e;
	//S.top++;
	return 1;
}
int Pop(SqStack &S,int &e)
{
	//����ջ��Ԫ��,��e��ʾ��ʧ�ܷ���-1���ɹ�����1
	if (S.top==S.base) return -1;
	e= *--S.top;
	return 1; 
}
int GetTop(SqStack &S,int &e)
{
	//���ջ����Ԫ��
	if (S.top==S.base) return -1;
	e = *(S.top-1);
	return 1; 
}
int Destory(SqStack &S)
{
	//����ջ
	if (S.stacksize!=0)
		free(S.base);
	return 0; 
} 
void print(SqStack &S)
{
	//��ӡջ��Ԫ��
	if (S.top!=S.base) {//ջ�ǿ� 
		cout<<"ջ��->";
		int *pmove=S.top; 
		while (pmove!=S.base) {
			cout<<*--pmove<<"->";
		
		} 
		cout<<"ջ��"<<endl;
	}
	else
		cout<<"��ջ��"<<endl;
}
//���������� 
int main()
{
	SqStack stack1;
	int temp;
	if (InitStack(stack1)==-1) {
		//
		cout<<"�ڴ����ʧ��"<<endl;
		return -1;
	}
	for (int j=0;j<10;j++)
	if(Push(stack1,j)!=1) exit(1);
	cout<<stack1.stacksize<<endl;
	print(stack1);
	Pop(stack1,temp);
	print(stack1);
	cout<<temp<<endl;
	
	return 0;
}

