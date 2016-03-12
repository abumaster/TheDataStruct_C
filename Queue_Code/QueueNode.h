//链式队列的节点 
template<typename type> class LinkQueue;
template<typename type> class QNode {
	public:
		friend class LinkQueue<type>;
		QNode(type item):m_data(item), m_pnext(NULL) {
		}
	private:
		type m_data;
		QNode<type> *m_pnext;
};
