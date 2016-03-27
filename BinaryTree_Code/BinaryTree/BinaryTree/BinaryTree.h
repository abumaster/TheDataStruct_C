#include "BinaryTreeNode.h"

template<typename type> class BinaryTree {
public:
	BinaryTree() :m_proot(NULL){}
	BinaryTree(const type stop) :m_stop(stop), m_proot(NULL){}
	BinaryTree(BinaryTree<type> &copy);//�������캯��
	virtual ~BinaryTree() {
		m_proot->Destory();
	}
	virtual bool IsEmpty() {
		return m_proot == NULL;
	}

	//��õ�ǰ���ģ����ҡ�˫�ס���
	virtual BinTreeNode<type> *GetLeft(BinTreeNode<type> *current);
	virtual BinTreeNode<type> *GetRight(BinTreeNode<type> *current);
	virtual BinTreeNode<type> *GetParent(BinTreeNode<type> *current);
	const BinTreeNode<type> *GetRoot() const;
	virtual bool Insert(const type item);
	virtual BinTreeNode<type> *Find(const type item) const;
	//����
	void InOrder();
	void PreOrder();
	void PostOrder();

	int Size();
	int Height();

	//���������
	BinaryTree<type> & operator=(const BinaryTree<type> copy);
	friend bool  operator==<type>(const BinaryTree<type> s,
		const BinaryTree<type> t);
	friend ostream& operator<< <type>(ostream&, BinaryTree<type>&);
	friend istream& operator>> <type>(istream&, BinaryTree<type>&);

private:
	type m_stop;//������־
	BinTreeNode<type> *m_proot;//��

	BinTreeNode<type> *GetParent(BinTreeNode<type> *start, 
		BinTreeNode<type> *current);//�ҵ���ǰ��˫�׽��
	void Print(BinTreeNode<type> *start, int n = 0);

};

template<typename type> BinaryTree<type>::BinaryTree(BinaryTree<type> &copy)
{
	if (copy.m_proot) {
		this->m_stop = copy.m_stop;
	}
	m_proot = m_proot->Copy(copy.m_proot);
}
template<typename type> BinTreeNode<type>* 
BinaryTree<type>::GetLeft(BinTreeNode<type> *current)
{
	return m_proot&&current ? current->m_pleft : NULL;
}
template<typename type> BinTreeNode<type>* 
BinaryTree<type>::GetRight(BinTreeNode<type> *current)
{
	return m_proot&&current ? current->m_pright : NULL;
}
template<typename type> const BinTreeNode<type>* BinaryTree<type>::GetRoot() const
{
	return m_proot;
}
template<typename type> BinTreeNode<type>* 
BinaryTree<type>::GetParent(BinTreeNode<type> *start, BinTreeNode<type> *current)
{
	if (start == NULL || current == NULL) {
		return NULL;
	}
	if (start->m_pleft == current || start->m_pright == current) {
		return start;
	}
	BinTreeNode<type> *pmove;
	if ((pmove = GetParent(start->m_pleft, current)) != NULL) {
		return pmove;
	}
	else {
		return GetParent(start->m_pright, current);
	}
}
template<typename type> BinTreeNode<type>* 
BinaryTree<type>::GetParent(BinTreeNode<type> *current)
{
	return current == NULL || current == m_proot ? NULL : GetParent(m_proot, current);
}

template<typename type> bool BinaryTree<type>::Insert(const type item)
{
	//�����в������ݣ�ƽ�������
	BinTreeNode<type> *pstart = m_proot;
	BinTreeNode<type> *newnode = new BinTreeNode<type>(item);//�µĽ��
	if (m_proot == NULL)  {
		m_proot = newnode;
		return 1;
	}
	while (1) {//���������ҵ����ʵĲ���λ��
		if (pstart->m_data == item) {
			cout << "the item: " << item << " is exist!" << endl;
			return 0;//����ʧ��
		}
		if (item < pstart->m_data) {//С�Ĳ���������
			if (pstart->m_pleft == NULL) {
				pstart->m_pleft = newnode;
				return 1;//����ɹ�
			}
			pstart = pstart->m_pleft;//����
		}
		else {//������
			if (pstart->m_pright == NULL) {
				pstart->m_pright = newnode;
				return 1;
			}
			pstart = pstart->m_pright;
		}
	}
}
template<typename type> BinTreeNode<type>* BinaryTree<type>::Find(
	const type item) const//��ֵ����
{
	//�����ʱ���Ѿ���ƽ�Ͷ�����
	BinTreeNode<type> *pstart = m_proot;
	while (pstart) {
		if (pstart->m_data == item)
			return pstart;
		if (item < pstart->m_data)//��������
			pstart = pstart->m_pleft;
		else
			pstart = pstart->m_pright;
	}
	return NULL;
}
template<typename type> 
void BinaryTree<type>::Print(BinTreeNode<type> *start,int n)
{
	if (start == NULL) {
		for (int i = 0; i < n; i++) {
			cout << "	";
		}
		cout <<"NULL"<<endl;
		return;
	}
	Print(start->m_pright, n + 1);	//print the right subtree
	for (int i = 0; i < n; i++){	//print blanks with the height of the node
		cout << "	";
	}
	if (n >= 0){
		cout << start->m_data << "--->" << endl;//print the node
	}
	Print(start->m_pleft, n + 1);	//print the left subtree
}
template<typename type> 
BinaryTree<type>& BinaryTree<type>::operator=(const BinaryTree<type> copy)
{
	if (copy.m_proot)
		this->m_stop = copy.m_stop;
	m_proot = m_proot->Copy(copy.m_proot);
	return *this;
}
template<typename type>
ostream& operator<<(ostream &os, BinaryTree<type>& out)
{
	out.Print(out.m_proot);
	return os;
}
template<typename type> istream&
operator>>(istream &is, BinaryTree<type>& initem)
{
	type item;
	cout << "init tree" << endl << "end with (" << initem.m_stop << ")!" <<endl;
	is >> item;
	while (item!=initem.m_stop)
	{
		initem.Insert(item);
		is >> item;
	}
	return is;
}
template<typename type>
bool operator==(const BinaryTree<type> s, const BinaryTree<type> t)
{
	return equal(s.m_proot, t.m_proot);
}
template<typename type>
void BinaryTree<type>::InOrder()
{
	this->m_proot->InOrder();
}
template<typename type>
void BinaryTree<type>::PreOrder()
{
	this->m_proot->PreOrder();
}
template<typename type>
void BinaryTree<type>::PostOrder()
{
	this->m_proot->PostOrder();
}

template<typename type> int BinaryTree<type>::Size()
{
	return this->m_proot->Size();
}
template<typename type> int BinaryTree<type>::Height()
{
	return this->m_proot->Hight();
}
