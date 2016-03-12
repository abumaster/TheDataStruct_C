//链表队列
#include <iostream>
#include "QueueNode.h"
using namespace std;
template <typename type> class LinkQueue {
	public:
		LinkQueue():m_pfrond(NULL), m_prear(NULL) {
		}
		~LinkQueue() {
			ClearQueue();
		}
	public:
		void ClearQueue();
		void EnQueue(type item);
		type DeQueue();
		type GetHead();
		bool QueueEmpty();
		void PrintQueue();
		int QueueLength();
		
	private:
		QNode<type> *m_pfrond,*m_prear;
}; 
template<typename type> void LinkQueue<type>::ClearQueue()
{
	//清空队列，从头开始
	QNode<type> *pdel;
	//m_pdel=m_pfront;
	while (m_pfrond) {//有元素 
		pdel=m_pfrond;
		m_pfrond=m_pfrond->m_pnext;
		delete pdel;
	} 
}
template<typename type> void LinkQueue<type>::EnQueue(type item)
{
	//向队列中加入元素，
	if (m_pfrond==NULL) {
		m_pfrond=m_prear=new QNode<type>(item);
	} 
	else {//从队尾添加 
		m_prear=m_prear->m_pnext=new QNode<type>(item);
	}
}

template<typename type> type LinkQueue<type>::DeQueue()
{
	if (QueueEmpty()) {
		cout<<"Queue is empty"<<endl;
		exit(1);
	}
	QNode<type> *pdel;
	pdel=m_pfrond;
	m_pfrond=m_pfrond->m_pnext;
	type item=pdel->m_data;
	delete pdel;
	return item;
}
template<typename type>	type LinkQueue<type>::GetHead()
{
	if (QueueEmpty()) {//empty queue
		cout<<"the queue is empty"<<endl;
		exit(1);
	}
	return m_pfrond->m_data;	
}
template<typename type>	bool LinkQueue<type>::QueueEmpty()
{
	return m_pfrond==NULL;
}
template<typename type>	void LinkQueue<type>::PrintQueue()
{
	QNode<type> *pmove;
	pmove=m_pfrond;
	cout<<"Front<=";
	while (pmove) {
		cout<<pmove->m_data<<"<=";
		pmove=pmove->m_pnext;
	}
	cout<<"Rear"<<endl;
}
template<typename type> int LinkQueue<type>::QueueLength()
{
	int length=0;
	QNode<type> *pmove=m_pfrond;
	while (pmove) {
		++length;
		pmove=pmove->m_pnext;
	}	
	return length;
}


