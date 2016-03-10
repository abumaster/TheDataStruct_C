/*	插入排序的使用
*	数据结构 P265 算法10.1
*	2016/3/10 @张国丰
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
	KeyType key;//关键字记录项
	//other 
}RedType;
typedef struct {
	RedType r[MAXSIZE+1];//一个空间用作哨兵]
	int length; 
}SqList; 

SqList myList;//全局变量，顺序表 
 
void initList()
{
	//初始化顺序表
	int i=1;
	memset(myList.r,0,MAXSIZE+1);
	for(; i<MAXSIZE+1; i++) {
		//srand(i);
		myList.r[i].key=rand()%20;
	} 
	myList.length=MAXSIZE;
}
bool comp(KeyType a, KeyType b)//a<b return true
{
	return a<b;
} 
void InsertSort(SqList &L) 
{
	//插入排序算法 ，递增序 
	int i,j;
	for (i=2; i<=L.length; ++i) {
		if (comp(L.r[i].key, L.r[i-1].key)) {
			L.r[0]=L.r[i];//每次保存当前排好序的最小值 
			//cout<<&L.r[i];
			L.r[i]=L.r[i-1];
			for (j=i-2; comp(L.r[0].key, L.r[j].key); --j) {
				L.r[j+1]=L.r[j];//记录后移 
			}
			L.r[j+1]=L.r[0];//插入到正确位置 
		}
	}
}
void Print(SqList &L)
{
	for (int i=1;i<=L.length;i++) {
		cout<<L.r[i].key<<" ";
	}
	cout<<endl;
}
int main()
{
	//主函数
	initList(); 
	Print(myList);
	InsertSort(myList);
	Print(myList);
	
	return 0;
}
