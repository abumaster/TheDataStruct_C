#include <iostream>
using namespace std;
/*���Ա����ʽ��ʾ��ʵ��
*	@2016.3.3 zgf 
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;
*/
template <typename Type> class LinkList;
/*  ��������Ľ��ṹ 
    �������ݺ�һ��ָ�� 
*/
template <typename Type> class LNode {
	public:
		//friend typename LinkList<Type>;
		LNode():m_pnext(NULL) {
		}
		LNode(const Type item, LNode<Type> *next=NULL):m_data(item),m_pnext(next) {
		}
		~LNode(){
			m_pnext=NULL;
		}
	public:
		Type GetData();
	//	friend ostream& operator<< <Type>(ostream&, LNode<Type>&);
	public:
		Type m_data;
		LNode *m_pnext;
};
template<typename Type> Type LNode<Type>::GetData()
{
	return this->m_data;
}
/*
template<typename Type> ostream& operator<< <Type> (ostream& os, LNode<Type>& out)
{
	os<<out.m_data;
	return os;
}*/
//�������� 
template <typename Type> class LinkList {
	public :
		LinkList():head(new LNode<Type>()) {}
		~LinkList(){
			MakeEmpty();
			delete head;
		}
	public:
		void MakeEmpty();
		int Length();                           //��ȡ����ĳ��� 
		LNode<Type> *Find(Type value,int n); 	//����ֵ 
		LNode<Type> *Find(int n);            
		bool Insert(Type item,int n=0);         //��nλ�ò������� 
		Type Remove(int n=0);                   //�Ƴ�nλ�õ����� 
		bool RemoveAll(Type item);              //ɾ��item������ 
		Type Get(int n);                        //��ȡnλ�õ����� 
		void Print();                           //��ӡ��Ϣ 
	private:
		LNode<Type> *head;

};
template<typename Type> void LinkList<Type>::MakeEmpty()
{
	LNode<Type> *pdel;
	while (head->m_pnext != NULL) {//ͷ������һ���ǿ�  
 		pdel = head->m_pnext;
 		head->m_pnext=pdel->m_pnext;//�ı�ָ�� 
 		delete pdel;
	}
}
template<typename Type> int LinkList<Type>::Length()
{
	LNode<Type> *pmove = head->m_pnext;
	int count=0;
	while (pmove!=NULL) { //���ǽ�β����ƶ� ������ 
		pmove=pmove->m_pnext;
		count++;
	}
	return count;
}

template<typename Type> LNode<Type> *LinkList<Type>::Find(Type value,int n)
{
	
}
template<typename Type> LNode<Type> *LinkList<Type>::Find(int n)
{//���ҵ�n��Ԫ�أ�����ָ������ָ��
	if (n<0) {
		cout << "The n is out of boundary"<<endl;
		return NULL; 
	} 
	LNode<Type> *pmove=head->m_pnext;
	for (int i=0; i<n&&pmove; i++) {
		pmove=pmove->next;
	}
	if (pmove==NULL) {
		cout<<"no n is find"<<endl;
		return NULL;
	}
	return pmove; 
	
}
template<typename Type> bool LinkList<Type>::Insert(Type item, int n) 
{
	if (n<0) {
		cout<<"Insert position is illegal"<<endl;
		return 0;
	}
	LNode<Type> *pmove=head;
	LNode<Type> *pnode=new LNode<Type>(item);//����һ���ڵ�ռ�
	if (pnode==NULL) {
		cout<<"application memery is error"<<endl;
		return 0;
	}
	//��ָ���ƶ���Ҫ�����λ��
	for (int i=0;i<n && pmove; i++) {
		pmove=pmove->m_pnext;
	} 
	//�Ƿ񵽴���β�ڵ㻹û���ҵ������λ�ã�
	//�����λ��Խ�� 
	if (pmove==NULL) {
		cout<<"insert is error"<<endl;
		return 0;
	}
	//��ʼִ�в������
	pnode->m_pnext=pmove->m_pnext;
	pmove->m_pnext=pnode; 
	return 1;
}
template<typename Type> bool LinkList<Type>::RemoveAll(Type item)
{
	LNode<Type> *pmove=head;
	LNode<Type> *pdel=head->m_pnext;
	while (pdel!=NULL) {
		if(pdel->m_data==item){//�ҵ���ɾ����Ԫ����ͬ�� 
			pmove->m_pnext=pdel->m_pnext;
			delete pdel;
			pdel=pmove->m_pnext;
			continue;
		}
		pmove=pmove->m_pnext;
		pdel=pdel->m_pnext;
	}
	return 1;
}
template<typename Type> Type LinkList<Type>::Remove(int n)
{//���������е�n��Ԫ��
	if (n<0) {
		cout<<"can not find this element"<<endl;
		exit(1);
	} 
	LNode<Type> *pmove=head,*pdel;
	for (int i=0; i<n && pmove->m_pnext; i++) {
		pmove=pmove->m_pnext;//һֱ�����������ҵ�n��Ԫ�� 
	}
	if (pmove->m_pnext == NULL) {
		cout<<"cant't find this element"<<endl;
		exit(1);
	}
	//��ʼɾ�����Ԫ��
	pdel=pmove->m_pnext;
	pmove->m_pnext=pdel->m_pnext;
	Type temp=pdel->m_data;
	delete pdel;
	return temp; 
}
template<typename Type> Type LinkList<Type>::Get(int n)
{
	if (n<0) {
		cout<<"can not find this element"<<endl;
		exit(1);
	} 
	LNode<Type> *pmove=head;
	for (int i=0; i<n; i++) {
		pmove=pmove->m_pnext;//һֱ�����������ҵ�n��Ԫ�� 
		if (pmove->m_pnext == NULL) {
		cout<<"cant't find this element"<<endl;
		exit(1);
		}
	}
	Type temp=pmove->m_pnext->m_data;
	return temp; 
}

template<typename Type> void LinkList<Type>::Print(){
	LNode<Type> *pmove=head->m_pnext;
	cout<<"head";
	while(pmove){
		cout<<"--->"<<pmove->m_data;
		pmove=pmove->m_pnext;
	}
	cout<<"--->over"<<endl<<endl;
}

