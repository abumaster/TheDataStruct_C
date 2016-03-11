/*顺序栈的模板及实现*/
#include <iostream>
using namespace std;

template<typename type> class SeqStack {
	
	public:
		SeqStack(int sz):m_ntop(-1),m_Maxsize(sz) {
			m_elements = new type[m_Maxsize];//初始化内存申请 
			if (m_elements==NULL) {
				cout<<"内存分配失败"<<endl;
				exit(1);
			}
		}
		~SeqStack() {
			delete[] m_elements;
		}
	public:
		//定义方法入栈，出栈，获取栈顶元素，清空栈，判断栈空，判断栈满，打印 
		int Push(const type item); 
		type Pop();
		type GetTop();
		void Print();
		void MakeEmpty() {
			m_ntop=-1;
		}
		bool IsEmpty() {
			return m_ntop==-1;
		}
		bool IsFull() {
			return m_ntop==m_Maxsize-1;
		}
	private:
		int m_ntop;//栈元素的指示坐标 
		type *m_elements;//栈
		int m_Maxsize; 

};

template<typename type> int SeqStack<type>::Push(const type item)
{
	if (IsFull()) {
		cout<<"The Stack is Full!"<<endl;
		return -1;
	}
	m_elements[++m_ntop]=item;
	return 0;
}
template<typename type> type SeqStack<type>::Pop()
{
	if (IsEmpty()) {
		cout << "The Stack Is Empty!"<<endl;
		exit(1);
	}
	return m_elements[m_ntop--];
}
template<typename type> type SeqStack<type>::GetTop()
{
	if (IsEmpty()) {
		cout<<"The Stack is Empty!"<<endl;
		return;
	}
	return m_elements[m_ntop];
}
template<typename type> void SeqStack<type>::Print()
{
	int m_move=m_ntop;
	cout<<"栈顶=>";
	while (m_move!=-1) {
		cout<<m_elements[m_move--]<<"=>";
	}
	cout<<"栈底"<<endl;
}




