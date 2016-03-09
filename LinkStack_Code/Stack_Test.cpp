#include <iostream>
using namespace std;
#include "LinkStack.h"

int main()
{
	LinkStack<int> sk;
	for (int i=0; i<10; i++) {
		sk.Push(i);
	}
	sk.Print();
	cout<<"get top is: "<<sk.GetTop()<<endl;
	sk.Pop();
	cout<<"pop one "<<endl;
	sk.Print();
	sk.Push(100);
	cout<<"push one "<<endl;
	sk.Print();
	sk.MakeEmpty();
	sk.Print();
	sk.Pop();
}
