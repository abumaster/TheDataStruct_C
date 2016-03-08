#include <iostream>
using namespace std;
/*线性表的链式表示和实现
*	@2016.3.3 zgf 
*/
/*
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;
*/
template <typename Type> class LinkList;
/*  定义链表的结点结构 
    包括数据和一个指针 
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
//定义链表 
template <typename Type> class LinkList {
	public :
		LinkList():head(new LNode<Type>()) {}
		~LinkList(){
			MakeEmpty();
			delete head;
		}
	public:
		void MakeEmpty();
		int Length();                           //获取链表的长度 
		LNode<Type> *Find(Type value,int n); 	//查找值 
		LNode<Type> *Find(int n);            
		bool Insert(Type item,int n=0);         //在n位置插入数据 
		Type Remove(int n=0);                   //移除n位置的数据 
		bool RemoveAll(Type item);              //删除item的数据 
		Type Get(int n);                        //获取n位置的数据 
		void Print();                           //打印信息 
	private:
		LNode<Type> *head;

};
template<typename Type> void LinkList<Type>::MakeEmpty()
{
	LNode<Type> *pdel;
	while (head->m_pnext != NULL) {//头结点的下一个非空  
 		pdel = head->m_pnext;
 		head->m_pnext=pdel->m_pnext;//改变指针 
 		delete pdel;
	}
}
template<typename Type> int LinkList<Type>::Length()
{
	LNode<Type> *pmove = head->m_pnext;
	int count=0;
	while (pmove!=NULL) { //不是结尾向后移动 ，计数 
		pmove=pmove->m_pnext;
		count++;
	}
	return count;
}

template<typename Type> LNode<Type> *LinkList<Type>::Find(Type value,int n)
{
	
}
template<typename Type> LNode<Type> *LinkList<Type>::Find(int n)
{//查找第n个元素，返回指向它的指针
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
	LNode<Type> *pnode=new LNode<Type>(item);//申请一个节点空间
	if (pnode==NULL) {
		cout<<"application memery is error"<<endl;
		return 0;
	}
	//将指针移动到要插入的位置
	for (int i=0;i<n && pmove; i++) {
		pmove=pmove->m_pnext;
	} 
	//是否到达了尾节点还没有找到插入的位置，
	//插入的位置越界 
	if (pmove==NULL) {
		cout<<"insert is error"<<endl;
		return 0;
	}
	//开始执行插入操作
	pnode->m_pnext=pmove->m_pnext;
	pmove->m_pnext=pnode; 
	return 1;
}
template<typename Type> bool LinkList<Type>::RemoveAll(Type item)
{
	LNode<Type> *pmove=head;
	LNode<Type> *pdel=head->m_pnext;
	while (pdel!=NULL) {
		if(pdel->m_data==item){//找到与删除的元素相同的 
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
{//查找链表中第n个元素
	if (n<0) {
		cout<<"can not find this element"<<endl;
		exit(1);
	} 
	LNode<Type> *pmove=head,*pdel;
	for (int i=0; i<n && pmove->m_pnext; i++) {
		pmove=pmove->m_pnext;//一直向后遍历，查找第n个元素 
	}
	if (pmove->m_pnext == NULL) {
		cout<<"cant't find this element"<<endl;
		exit(1);
	}
	//开始删除这个元素
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
		pmove=pmove->m_pnext;//一直向后遍历，查找第n个元素 
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

