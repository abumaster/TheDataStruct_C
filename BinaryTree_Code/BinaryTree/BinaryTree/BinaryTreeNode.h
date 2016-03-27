/* �������Ľ��
*/

template<typename type> class BinaryTree;

template<typename type> class BinTreeNode {
	friend class BinaryTree<type>;
	
public:
	//���캯��
	BinTreeNode() :m_pleft(NULL), m_pright(NULL){}
	BinTreeNode(type item,
		BinTreeNode<type> *left = NULL,BinTreeNode<type> *right = NULL) 
		:m_data(item),m_pleft(left), m_pright(right) {}

	type GetData() const;//��ý������
	BinTreeNode<type> *GetLeft() const;//�������ָ�� 
	BinTreeNode<type> *GetRight() const;

	void SetData(const type data);
	void SetLeft(const BinTreeNode<type> *left);
	void SetRight(const BinTreeNode<type> *right);

	//����
	void InOrder();
	void PreOrder();
	void PostOrder();

	int Size();
	int Hight();
	BinTreeNode<type> *Copy(BinTreeNode<type> *copy);

	void Destory() {
		if (this != NULL) {
			this->m_pleft->Destory();
			this->m_pright->Destory();
			delete this;
		}
	}
	friend bool equal<type>(const BinTreeNode<type> *s,
		const BinTreeNode<type> *t);

private:
	BinTreeNode<type> *m_pleft, *m_pright;//���Һ���ָ��
	type m_data;//���ڵ������
};

template<typename type> type BinTreeNode<type>::GetData() const
{
	if (this != NULL)
		return this->m_data;
	return -1;
}
template<typename type> BinTreeNode<type> * BinTreeNode<type>::GetLeft() const
{
	//�������ָ�� 
	if (this != NULL)
		return this->m_pleft;
	return NULL;

}
template<typename type> BinTreeNode<type> * BinTreeNode<type>::GetRight() const
{
	return this != NULL ? this->m_pright : NULL;
}
template<typename type> void BinTreeNode<type>::SetData(const type data)
{
	if (this != NULL)
		m_data = data;
}
template<typename type> void BinTreeNode<type>::SetLeft(const BinTreeNode<type> *left)
{
	if (this != NULL)
		this->m_pleft = left;
}
template<typename type> void BinTreeNode<type>::SetRight(const BinTreeNode<type> *right)
{
	if (this != NULL)
		this->m_pright = right;
}

template<typename type> BinTreeNode<type>* BinTreeNode<type>::Copy(BinTreeNode<type> *copy)
{
	if (copy == NULL) {
		return NULL;
	}
	BinTreeNode<type> *temp = new BinTreeNode<type>(copy->m_data);
	//temp->m_pleft = copy->m_pleft;
	//temp->m_pright = copy->m_pright;
	temp->m_pleft = Copy(copy->m_pleft);
	temp->m_pright = Copy(copy->m_pright);
	return temp;
}
template<typename type> bool equal(const BinTreeNode<type> *s,
	const BinTreeNode<type> *t)
{
	if (s == NULL && t == NULL)
		return 1;
	if (s&&t&&s->m_data == t->m_data&&equal(s->m_pleft, t->m_pright)
		&& equal(s->m_pright, t->m_pright))
		return 1;
	return 0;
}

template<typename type> void BinTreeNode<type>::InOrder()
{
	if (this != NULL) {
		this->m_pleft->InOrder();
		cout << "--->" << this->m_data;
		this->m_pright->InOrder();
	}
}
template<typename type> void BinTreeNode<type>::PreOrder()
{
	if (this != NULL) {
		cout << "--->" << this->m_data;
		this->m_pleft->PreOrder();
		this->m_pright->PreOrder();
	}
}
template<typename type> void BinTreeNode<type>::PostOrder()
{
	if (this != NULL) {
		this->m_pleft->PostOrder();
		this->m_pright->PostOrder();
		cout << "--->" << this->m_data;
	}
}
template<typename type> int BinTreeNode<type>::Size()
{
	if (this == NULL)
		return 0;
	//����+�Һ���+��
	return 1 + this->m_pleft->Size() + this->m_pright->Size();
}
template<typename type> int BinTreeNode<type>::Hight()
{//���ϸ�
	if (this == NULL)
		return 0;
	int lheight, rheight;
	lheight = this->m_pleft->Hight();
	rheight = this->m_pright->Hight();
	return 1+(lheight > rheight ? lheight : rheight);
}