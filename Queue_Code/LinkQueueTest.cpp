#include <iostream>
using namespace std;
#include "LinkQueue.h"
/*	��ʽ���е�Ӧ�� 
*/
int main()
{
	LinkQueue<int> lq;
	lq.PrintQueue();
	for (int x=0; x<12; x++) {
		lq.EnQueue(x);
	}
	lq.PrintQueue();
	cout<<"Length:	"<<lq.QueueLength()<<endl;
	cout<<"delete one:	"<<lq.DeQueue()<<"	"<<lq.QueueLength()<<endl;
	lq.PrintQueue();
	cout<<lq.QueueLength();
	return 0;
}
