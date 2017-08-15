/*doubly_linked_list*/ 
#include <iostream> 

/*双向链表*/
/*用模板类实现*/

using namespace std;

typedef unsigned int u32;

template <typename T>
class DoublyLinkedList;

template <typename T>
class DoublyLinkedList
{
private:
	class _node
	{
	public:
			//
	private:
		friend class DoublyLinkedList;//声明为链表类的友元
		T _data;
		_node* _last;
		_node* _next;
		
		_node(T d,_node* l,_node* n):
		_data(d),
		_last(l),
		_next(n){}
	};

public:
	class iterator
	{
	public:
		friend class DoublyLinkedList<T>;
		iterator();
		iterator next();
		iterator last();
		bool hasNext();
		bool hasLast();
		bool isValid(){return m_node != NULL;}//当前迭代器是否合法
		iterator operator++();
		iterator operator--();
		iterator operator++(int);
		iterator operator--(int);
		T& operator*(){return m_node->_data;}
		operator bool(){return isValid();}
	private:
		iterator(DoublyLinkedList::_node* n):
		m_node(n){};
		typename DoublyLinkedList::_node* m_node;
	};
	friend class iterator;
	
	DoublyLinkedList(u32 max=(u32)-1);
	~DoublyLinkedList();	
	iterator tail() const;
	iterator head() const;
	iterator at(u32 index);
	T& operator[](int index);

	bool removeFromTail(T&);
	bool removeFromHead(T&);
	bool addToTail(const T& d);
	bool addToHead(const T&);
	
	void 	clear();//清除整个链表
	u32 	size(){return _size;}//元素个数
	bool 	isEmpty(){return _size==0;}//测试链表是否空
	void 	reverse();
	
private:
	_node *_head,*_tail;
	u32 _size,_maxsize;
};

//构造函数
// m为链表的最大长度
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(unsigned int m):
	_head(NULL),
	_tail(NULL),
	_size(0),
	_maxsize(m)
{
	
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::tail() const
{
	return typename DoublyLinkedList<T>::iterator(_tail);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::head() const
{
	return typename DoublyLinkedList<T>::iterator(_head);
}

template <typename T>
bool DoublyLinkedList<T>::removeFromTail(T& d)
{
	if(_tail && _size)
	{
		d = _tail->_data;//读取表尾的值	
		_node* tmp = _tail;//暂存当前的表尾指针
		_tail = _tail->_last;//将表尾指针改为上一个节点的指针
		if(_size != 1)//如果移除当前节点后表不为空
			_tail->_next = NULL;//把表尾指针的下一个节点指针置为0
		delete tmp;//释放被移除的节点的内存
		--_size;//链表长度减一
		return true;
	}
	else return false;
}

template <typename T>
bool DoublyLinkedList<T>::removeFromHead(T& d)
{
	if(_head && _size)
	{
		d = _head->_data;
		_node* tmp = _head;
		_head = _head->_next;
		if(_size != 1)//如果移除当前节点后表不为空
			_head->_last = NULL;//将下一节点指向上级节点的指针置0
		delete tmp;
		--_size;
		return true;
	}
	else return false;
}

template <typename T>
bool DoublyLinkedList<T>::addToTail(const T& d)
{
	if (_size+1 > _maxsize)//如果长度大于设定最大长度，返回false
		return false;
	if(isEmpty())//如果是空链表
		_head = _tail = new _node(d,NULL,NULL);//建立一个新的节点
	else
	{
		_tail->_next = new _node(d,_tail,NULL);//建立一个新节点并且将它的指针赋给上一节点
		_tail = (_tail->_next);//尾节点指针指向新建的节点
	}
	++_size;//链表长度自增
	return true;
}

template <typename T>
bool DoublyLinkedList<T>::addToHead(const T& d)
{
	if (_size+1 > _maxsize)
		return false;
	if(isEmpty())
		_head = _tail = new _node(d,NULL,NULL);
	else
	{
		_head->_last =  new _node(d,NULL,_head);
		_head = (_head->_last);
	}
	++_size;
	return true;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::at(u32 index)
{
	if(index+1 > _size)return iterator(NULL);
	
	_node* tmp = _head;
	for(u32 i=0;i<index;++i)
	{
		tmp = tmp->_next;
	}
	return iterator(tmp);
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
	return *at(index);
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	T d;
	while(removeFromHead(d));//历遍链表，删除所有数据并释放内存
}

template <typename T>
void DoublyLinkedList<T>::reverse()
{
	if(isEmpty())return;	

	//cur的步进表达式是cur = cur->_last而不是next，因为链表反序以后原来的下一个现在变成了上一个了。
	_node* mid;
	for(_node* cur = _head;cur!=0;cur = cur->_last)
	{
		mid = cur->_next;
		cur->_next = cur->_last;
		cur->_last = mid;
	}
	mid = _head;//swap()
	_head = _tail;
	_tail = mid;
}

//返回该迭代位置有没有上一个节点/下一个节点
template <typename T>
bool DoublyLinkedList<T>::iterator:: hasNext()
{
	cout << m_node->_next <<endl;
	return m_node->_next != NULL;
}

template <typename T>
bool DoublyLinkedList<T>::iterator:: hasLast()
{
	return m_node->_last != NULL;
}

//返回上一个节点或下一个节点的迭代器
template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::next()
{
	if(!hasNext())return iterator(NULL);
	
	return iterator(m_node->_next);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::last()
{
	if(!hasLast())return iterator(NULL);
	
	return iterator(m_node->_last);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator++()
{
	m_node = m_node->_next;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator--()
{
	m_node = m_node->_last;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator++(int)
{
	typename DoublyLinkedList<T>::iterator it(m_node);
	m_node = m_node->_next;
	return it;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::iterator::operator--(int)
{
	typename DoublyLinkedList<T>::iterator it(m_node);
	m_node = m_node->_last;
	return it;
}

int main()
{
	DoublyLinkedList<int> ls(5);
	int a,b;
	
	ls.addToTail(15);//15
	ls.addToHead(12);//12 15
	ls.removeFromTail(a);//12
	ls.addToTail(12);//12 12
	ls.addToTail(23);//12 12 23
	ls.removeFromTail(a);//12 12
	ls.removeFromTail(a);//12
	ls.addToHead(122);//122 12
	ls.addToHead(122);//122 122 12
	ls.addToHead(123);//123 122 122 12
	ls.addToTail(56);//123 122 122 12 56
	ls.addToTail(123);//123 122 122 12 56 //full
	ls.reverse();//56 12 122 122 123
	
	DoublyLinkedList<int>::iterator it = ls.head();
	for(int i=0;i<ls.size();++i)
	{
		cout << "Data: "<< (ls[i]) << " Size: " << ls.size() << endl;
	}
	
	return 0;
}
