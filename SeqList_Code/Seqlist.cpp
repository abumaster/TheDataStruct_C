#include <iostream>
//#include "Seqlist.h"
using namespace std;
//ͷ�ļ����庯����ʵ��
template <typename Type> 
int SeqList<Type>::Length()  
{
	return m_currentsize+1;
}
template <typename Type> int SeqList<Type>::Find(Type x) const
{
	for (int i=0; i<m_currentsize; i++) {
		if (m_elements[i] == x)
			return i;//ѭ����ô����ҵ��˾ͷ����ˣ�������ѭ��˵���Ҳ��� 
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
	//x�Ƿ���������Ա���
	int result = Find(x);
	if (result == -1)
		return 0;
	else 
		return 1; 
}
//��iλ�ò���xԪ�� ,��ȷ����1�����󷵻�0 
template <typename Type> int SeqList<Type>::Insert(Type x, int i)
{
	if (i<0 || i>m_currentsize+1 || m_currentsize==m_maxsize-1) {
		cout<<"����λ�÷Ƿ������߱�����"<<endl;
		return 0;
	}
	m_currentsize++;
	for (int j=m_currentsize; j>i; j--) {//i�Լ���֮���Ԫ��ȫ������ 
		m_elements[j] = m_elements[j-1];
	}
	m_elements[i] = x;
	return 1;	
}
template<typename Type> int SeqList<Type>::Remove(Type x)
{
	if (Find(x) == -1)
		return 0;
	for (int i=0; i<m_currentsize; i++) {
		if (m_elements[i] == x) {//�ҵ��ˣ���֮���Ԫ������ 
			//m_currentsize--;
			for (int j=i; j<m_currentsize; j++){
				m_elements[j] = m_elements[j+1];
			}
			m_currentsize--;
		}
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
template <typename Type> void SeqList<Type>::Print()
{
	cout << "���Ա�Ĵ�ӡ����ǣ�"<<endl;
	for (int i=0; i<m_currentsize; i++)
		cout<<i+1<<"\t"<<m_elements[i]<<endl;
	cout<<"-------------------------"<<endl;
}
