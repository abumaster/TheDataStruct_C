#include <iostream>
using namespace std;
#include "StackNode.h"
/* 	模板
*	列出链表存储的栈的基本操作 
*/
template <typename type>
class LinkStack{
	public:
		LinkStack():/*m_pbase(NULL), */m_ptop(NULL){
		}
		~LinkStack() {
			MakeEmpty();//释放空间 
		}
	public:
		void MakeEmpty();
		void Push(const type item);
		type Pop();
		type GetTop();
		void Print();
		bool IsEmpty() {
			return m_ptop==NULL;//空栈的判定条件 
		}
	private:
		//StackNode<type> *m_pbase;
		StackNode<type> *m_ptop;	
};
template<typename type> void LinkStack<type>::MakeEmpty()
{
	//将栈链表置空
	StackNode<type> *pmove;
	while (m_ptop!=NULL) {
		pmove=m_ptop;
		m_ptop=pmove->m_pnext;
		delete pmove;
	} 
}
template <typename type> void LinkStack<type>::Push(const type item)
{
	/*这一句什么意思呢？
	* 相当于链表，新申请的一个节点，数据item，
	* 下一条指向了前一个地址
	*/
	m_ptop=new StackNode<type>(item,m_ptop);
}
template<typename type>type LinkStack<type>::Pop()
{
	//从栈中弹出元素
	if (IsEmpty()) {//空栈
		cout<<"error! stack is empty"<<endl;
		exit(1);//非正常退出 
	}
	StackNode<type> *pdel=m_ptop;
	m_ptop=m_ptop->m_pnext;
	type temp=pdel->m_data;
	delete pdel;
	return temp; 
}
template<typename type>type LinkStack<type>::GetTop()
{
	if (IsEmpty()) {
		cout<<"error, stack is empty"<<endl;
		exit(1);
	}
	return m_ptop->m_data;
}
template<typename type> void LinkStack<type>::Print()
{
	StackNode<type> *pmove=m_ptop;
	cout<<"top=>";
	while (pmove!=NULL) {
		cout<<pmove->m_data<<"=>";
		pmove=pmove->m_pnext; 
	}
	cout<<"base"<<endl;
}
