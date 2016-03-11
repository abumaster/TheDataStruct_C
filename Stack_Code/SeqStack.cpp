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
	cout<<"原始栈是:"<<endl;
	mystack.Print();
	cout<<"Pop one: "<<mystack.Pop()<<endl;
	mystack.Print();
	cout<<"清空栈";
	mystack.MakeEmpty();
	mystack.Print();
	
	
	
	return 0;
}
