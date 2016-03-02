//Seqlist顺序表的模板
//!!类模板和函数的实现要放在一块 
#include <iostream>
#include <string>
using namespace std;
const int DefaultSize=100;

template <typename Type> class SeqList{
public:
	SeqList(int sz=DefaultSize)
		:m_maxsize(sz),m_currentsize(-1){
		if(sz>0){
			m_elements=new Type[m_maxsize];
		}
	}
	~SeqList(){
		delete[] m_elements;
	}
	int Length();
	int Find(Type x) const;				//find the position of x
	int isElement(Type x) const;		//is it in the list
	int Insert(Type x,int i);			//insert data
	int Remove(Type x);					//delete data
	int isEmpty();
	int isFull();
	Type Get(int i);
	void Print(string info = "默认") ;

private:
	Type *m_elements;
	const int m_maxsize;
	int m_currentsize;
};
template <typename Type> 
int SeqList<Type>::Length()  
{
	return m_currentsize+1;
}
template <typename Type> int SeqList<Type>::Find(Type x) const
{
	for (int i=0; i<m_currentsize; i++) {
		if (m_elements[i] == x)
			return i;//循环这么多次找到了就返回了，跳出了循环说明找不到 
		}
		/*else {
			cout<<"can not find this element!"<<endl;
			return -1;
		}*/
		cout<<"can't find this element!"<<endl;
		return -1;
	//}
}
template <typename Type> int SeqList<Type>::isElement(Type x) const
{
	//x是否存在在线性表中
	int result = Find(x);
	if (result == -1)
		return 0;
	else 
		return 1; 
}
//在i位置插入x元素 ,正确返回1，错误返回0 
template <typename Type> int SeqList<Type>::Insert(Type x, int i)
{
	if (i<0 || i>m_currentsize+1 || m_currentsize==m_maxsize-1) {
		cout<<"插入位置非法，或者表已满"<<endl;
		return 0;
	}
	m_currentsize++;
	for (int j=m_currentsize; j>i; j--) {//i以及它之后的元素全部后移 
		m_elements[j] = m_elements[j-1];
	}
	m_elements[i] = x;
	return 1;	
}
template<typename Type> int SeqList<Type>::Remove(Type x)
{
	
	if (Find(x) == -1)
		return 0;
		//这一句for 的奇妙之处：
		//找到了更改循环条件，避免漏掉 
	for (int i=0; i<m_currentsize; ) {
		if (m_elements[i] == x) {//找到了，它之后的元素左移 
			//m_currentsize--;
			for (int j=i; j<m_currentsize; j++){
				m_elements[j] = m_elements[j+1];
			}
			m_currentsize--;
			continue;
		}
		i++;
	}
	return 1;
}
template <typename Type> int SeqList<Type>::isEmpty()
{
	return m_currentsize == -1;
}
template <typename Type> int SeqList<Type>::isFull()
{
	return m_currentsize == m_maxsize-1;
}
template <typename Type> Type SeqList<Type>::Get(int i)
{
	if (i<0 || i>m_currentsize) {
		cout << "can't find this postiion !" <<endl;
		return 0;	
	}
	return m_elements[i];
			
}
template <typename Type> void SeqList<Type>::Print(string info)
{
	cout << "线性表的打印结果是："<<"\t"<<info<<endl;
	for (int i=0; i<m_currentsize; i++)
		cout<<i+1<<"\t"<<m_elements[i]<<endl;
	cout<<"-------------------------"<<endl;
}
