#include "BinaryTreeNode.h"

template<typename type> class BinaryTree {
public:
	BinaryTree() :m_proot(NULL){}
	BinaryTree(const type stop) :m_stop(stop), m_proot(NULL){}
	BinaryTree(BinaryTree<type> &copy);//拷贝构造函数
	virtual ~BinaryTree() {
		m_proot->Destory();
	}
	virtual bool IsEmpty() {
		return m_proot == NULL;
	}

	//获得当前结点的，左、右、双亲、根
	virtual BinTreeNode<type> *GetLeft(BinTreeNode<type> *current);
	virtual BinTreeNode<type> *GetRight(BinTreeNode<type> *current);
	virtual BinTreeNode<type> *GetParent(BinTreeNode<type> *current);
	const BinTreeNode<type> *GetRoot() const;
	virtual bool Insert(const type item);
	virtual BinTreeNode<type> *Find(const type item) const;
	//遍历
	void InOrder();
	void PreOrder();
	void PostOrder();

	int Size();
	int Height();

	//重载运算符
	BinaryTree<type> & operator=(const BinaryTree<type> copy);
	friend bool  operator==<type>(const BinaryTree<type> s,
		const BinaryTree<type> t);
	friend ostream& operator<< <type>(ostream&, BinaryTree<type>&);
	friend istream& operator>> <type>(istream&, BinaryTree<type>&);

private:
	type m_stop;//结束标志
	BinTreeNode<type> *m_proot;//根

	BinTreeNode<type> *GetParent(BinTreeNode<type> *start, 
		BinTreeNode<type> *current);//找到当前的双亲结点
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
	//向树中插入数据，平衡二叉树
	BinTreeNode<type> *pstart = m_proot;
	BinTreeNode<type> *newnode = new BinTreeNode<type>(item);//新的结点
	if (m_proot == NULL)  {
		m_proot = newnode;
		return 1;
	}
	while (1) {//遍历树，找到合适的插入位置
		if (pstart->m_data == item) {
			cout << "the item: " << item << " is exist!" << endl;
			return 0;//插入失败
		}
		if (item < pstart->m_data) {//小的插入左子树
			if (pstart->m_pleft == NULL) {
				pstart->m_pleft = newnode;
				return 1;//插入成功
			}
			pstart = pstart->m_pleft;//向下
		}
		else {//右子树
			if (pstart->m_pright == NULL) {
				pstart->m_pright = newnode;
				return 1;
			}
			pstart = pstart->m_pright;
		}
	}
}
template<typename type> BinTreeNode<type>* BinaryTree<type>::Find(
	const type item) const//按值查找
{
	//构造的时候已经是平和二叉树
	BinTreeNode<type> *pstart = m_proot;
	while (pstart) {
		if (pstart->m_data == item)
			return pstart;
		if (item < pstart->m_data)//在左子树
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
