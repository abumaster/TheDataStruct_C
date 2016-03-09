#include <iostream>
using namespace std;
#include "StackNode.h"
/* 	ģ��
*	�г�����洢��ջ�Ļ������� 
*/
template <typename type>
class LinkStack{
	public:
		LinkStack():/*m_pbase(NULL), */m_ptop(NULL){
		}
		~LinkStack() {
			MakeEmpty();//�ͷſռ� 
		}
	public:
		void MakeEmpty();
		void Push(const type item);
		type Pop();
		type GetTop();
		void Print();
		bool IsEmpty() {
			return m_ptop==NULL;//��ջ���ж����� 
		}
	private:
		//StackNode<type> *m_pbase;
		StackNode<type> *m_ptop;	
};
template<typename type> void LinkStack<type>::MakeEmpty()
{
	//��ջ�����ÿ�
	StackNode<type> *pmove;
	while (m_ptop!=NULL) {
		pmove=m_ptop;
		m_ptop=pmove->m_pnext;
		delete pmove;
	} 
}
template <typename type> void LinkStack<type>::Push(const type item)
{
	/*��һ��ʲô��˼�أ�
	* �൱�������������һ���ڵ㣬����item��
	* ��һ��ָ����ǰһ����ַ
	*/
	m_ptop=new StackNode<type>(item,m_ptop);
}
template<typename type>type LinkStack<type>::Pop()
{
	//��ջ�е���Ԫ��
	if (IsEmpty()) {//��ջ
		cout<<"error! stack is empty"<<endl;
		exit(1);//�������˳� 
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
