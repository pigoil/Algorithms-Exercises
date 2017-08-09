#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

template <typename T>
class BinarySearch;

template <typename T>
class BinarySearch
{
public:	
	static int rank(T key,T* a,int cnt);
};

template <typename T>
int BinarySearch<T>::rank(T key,T* a,int cnt)
{
	int lo=0;
	int hi=cnt-1;
	while(lo<=hi)
	{
		//int mid = lo + (hi - lo)/2;//分半	
		int mid = (lo + hi) /2;//分半			
		
		if(key < a[mid])
			hi = mid - 1;
		else if(key > a[mid])
			lo = mid + 1;
		else
		{
			return mid;//找得到
		}
	}
	return -1;//不存在
}

#endif

