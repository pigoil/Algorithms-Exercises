#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

template <typename T>
class BinarySearch;

template <typename T>
class BinarySearch
{
public:
	class Key
	{
	public:
		friend class BinarySearch<T>;
		Key(T d):
		_value(d),
		_repeat(0),
		_begin(0),
		_end(0)
		{}
		
		T value(){return _value;}
		unsigned int repeat(){return _repeat;}
		unsigned int beginIndex(){return _begin;}
		unsigned int endIndex(){return _end;}
	private:
		T _value;
		unsigned int _repeat;
		unsigned int _begin;
		unsigned int _end;
	};
	
	static bool rank(Key* k,T* a,unsigned int cnt);
};

template <typename T>
bool BinarySearch<T>::rank(Key* key,T* a,unsigned int cnt)
{
	unsigned int lo=0;
	unsigned int hi=cnt-1;
	while(lo<=hi)
	{
		unsigned int mid = (lo + hi)/2;//分半		
		
		if(key->_value < a[mid])
			hi = mid - 1;
		else if(key->_value > a[mid])
			lo = mid + 1;
		else
		{
			key->_repeat = 1;//找到了一个
			
			key->_begin = mid;//初始化头尾位置
			key->_end = mid;
			
			while(a[--key->_begin] == key->_value)//往前找
			{
				key->_repeat++;
			}
			while(a[++key->_end] == key->_value)//往后找
			{
				key->_repeat++;
			}
			key->_begin++,key->_end--;//被多减了一次
			return true;//找得到
		}
	}
	return false;//不存在
}

#endif

