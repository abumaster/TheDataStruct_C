#include <iostream>
using namespace std;

/*	栈的顺序存储实现
*	数据结构 P46 算法实现 
*	时间：20160308
*/
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef struct {//定义栈的结构，栈顶栈底指针，栈的大小 
	int *base;
	int *top;
	int stacksize;
}SqStack;

//栈的操作，包含初始化、入栈，出栈，获取栈顶元素
int InitStack(SqStack &S)
{
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S.base) {
		//cout<<"内存分配错误"<<endl;
		return -1;
	}
	S.top=S.base;//
	S.stacksize = STACK_INIT_SIZE;
	return 1;
} 
int Push(SqStack &S, int e)
{
	//将元素e压入栈，成功返回1，失败返回-1
	if ((S.top-S.base) >= S.stacksize) {//栈满加空间
		S.base =(int *)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(int));
		if (!S.base) return -1;//存储分配失败，非正常退出
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT; 
	} 
	*(S.top++) = e;
	//S.top++;
	return 1;
}
int Pop(SqStack &S,int &e)
{
	//返回栈顶元素,用e表示，失败返回-1，成功返回1
	if (S.top==S.base) return -1;
	e= *--S.top;
	return 1; 
}
int GetTop(SqStack &S,int &e)
{
	//获得栈顶的元素
	if (S.top==S.base) return -1;
	e = *(S.top-1);
	return 1; 
}
int Destory(SqStack &S)
{
	//销毁栈
	if (S.stacksize!=0)
		free(S.base);
	return 0; 
} 
void print(SqStack &S)
{
	//打印栈的元素
	if (S.top!=S.base) {//栈非空 
		cout<<"栈顶->";
		int *pmove=S.top; 
		while (pmove!=S.base) {
			cout<<*--pmove<<"->";
		
		} 
		cout<<"栈底"<<endl;
	}
	else
		cout<<"空栈！"<<endl;
}
//主函数测试 
int main()
{
	SqStack stack1;
	int temp;
	if (InitStack(stack1)==-1) {
		//
		cout<<"内存分配失败"<<endl;
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

