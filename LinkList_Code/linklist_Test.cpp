#include <iostream>
#include <string>
#include "Linklist.h"
using namespace std;

int main()
{
	LinkList<int> list1;
	for(int i=0;i<20;i++){
		list1.Insert(i*3,i);
	}
	for(int i=0;i<5;i++){
		list1.Insert(3,i*3);
	}
	cout<<"the Length of the list is "<<list1.Length()<<endl;
	list1.Print();
	cout<<"��10��Ԫ����: "<<list1.Get(10)<<endl;
	list1.Print();
	cout<<"ɾ����12��Ԫ��: "<<list1.Remove(12)<<endl;
	list1.Print();
	
	return 0;
}