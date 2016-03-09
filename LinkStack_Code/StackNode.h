template <typename type> class LinkStack;
template <typename type> 
class StackNode {
	private:
		friend class LinkStack<type>;
		StackNode(type data, StackNode<type> *next=NULL):
			m_data(data), m_pnext(next){
			}
	private:
		type m_data;
		StackNode<type> *m_pnext;		
};
