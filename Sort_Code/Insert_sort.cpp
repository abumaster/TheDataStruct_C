/*	���������ʹ��
*	���ݽṹ P265 �㷨10.1
*	2016/3/10 @�Ź���
*/
#include <iostream>
#include <string.h>
using namespace std;
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
	KeyType key;//�ؼ��ּ�¼��
	//other 
}RedType;
typedef struct {
	RedType r[MAXSIZE+1];//һ���ռ������ڱ�]
	int length; 
}SqList; 

SqList myList;//ȫ�ֱ�����˳��� 
 
void initList()
{
	//��ʼ��˳���
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
	//���������㷨 �������� 
	int i,j;
	for (i=2; i<=L.length; ++i) {
		if (comp(L.r[i].key, L.r[i-1].key)) {
			L.r[0]=L.r[i];//ÿ�α��浱ǰ�ź������Сֵ 
			//cout<<&L.r[i];
			L.r[i]=L.r[i-1];
			for (j=i-2; comp(L.r[0].key, L.r[j].key); --j) {
				L.r[j+1]=L.r[j];//��¼���� 
			}
			L.r[j+1]=L.r[0];//���뵽��ȷλ�� 
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
	//������
	initList(); 
	Print(myList);
	InsertSort(myList);
	Print(myList);
	
	return 0;
}
