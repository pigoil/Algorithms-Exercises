/*doubly_linked_list*/ 
#include <iostream> 

/*双向链表*/
/*用模板类实现*/

using namespace std;


template <typename T>
class DoublyLinkedList;

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList(unsigned int m = static_cast<unsigned int>(-1));
	~DoublyLinkedList();

	bool tail(T&) const;
	bool head(T&) const;
	bool removeFromTail(T&);
	bool removeFromHead(T&);
	
	bool addToTail(const T&);
	bool addToHead(const T&);
	
	unsigned int size(){return _size;};//返回链表的大小
	bool isEmpty(){return _size == 0;};//返回链表是否为空
	void clear();
	
private:
	class _node
	{
	public:
		T _data;//数据
		_node* _last;//上一个的指针
		_node* _next;//下一个的指针
		_node(T d,_node* l,_node* n)://node类构造函数
			_data(d),
			_last(l),
			_next(n)
			{}
	}*_head,*_tail;
	
	unsigned int _size;//链表长度
	unsigned int _maxsize;//链表最大长度
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

//析构函数
//清空整个链表，释放内存
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

//读取表尾/表头的值到d中，并返回成功与否
//该方法为const方法
template <typename T>
bool DoublyLinkedList<T>::tail(T& d) const
{
	if(_tail && _size)//如果不为空
	{
		d = _tail->_data;//读取数据而不做更改
		return true;
	}
	else return false;
}

template <typename T>
bool DoublyLinkedList<T>::head(T& d) const
{
	if(_head && _size)
	{
		d = _head->_data;
		return true;
	}
	else return false;
}

/*移除表尾/表头节点，将该节点的值读取到d中，并返回成功与否*/
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

/*在表尾/表头插入值d，并返回成功与否*/
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

/*清空整个链表*/
template <typename T>
void DoublyLinkedList<T>::clear()
{
	T d;
	while(removeFromHead(d));//历遍链表，删除所有数据并释放内存
}

int main()
{
	DoublyLinkedList<int> ls(5);
	int a,b;
	
	ls.addToTail(15);
	ls.addToHead(12);
	ls.removeFromTail(a);
	ls.addToTail(12);
	ls.addToTail(23);
	ls.removeFromTail(a);
	ls.removeFromTail(a);
	ls.addToHead(122);
	ls.addToHead(122);
	ls.addToHead(123);
	ls.addToTail(56);
	ls.addToTail(123); 
	
	while(ls.removeFromHead(a))
	{
		cout << "Data: "<< a << " Size: " << ls.size() <<endl;
	}
	return 0;
}
