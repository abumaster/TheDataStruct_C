#include <iostream>
using namespace std;
#include "SeqStack.h"

int main()
{
	SeqStack<int> mystack(20);
	for (int i=0; i<15; i++) {
		if(mystack.Push(i+2)<0) {
			break;
		}
	}
	cout<<"ԭʼջ��:"<<endl;
	mystack.Print();
	cout<<"Pop one: "<<mystack.Pop()<<endl;
	mystack.Print();
	cout<<"���ջ";
	mystack.MakeEmpty();
	mystack.Print();
	
	
	
	return 0;
}
