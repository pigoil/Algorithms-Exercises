#include <iostream>
#include "../20170808_merge_sort/top_to_bottom_merge_sort.h"
#include "../20170806_binary_search/binary_search.h"

using namespace std;

int main()
{
	const int N = 10;
	int array[N] = {2,322,4,-3,2,3,2,-2,3,2};
	//-3 -3 -2 2 2 2 2 3 4 322
	
	MergeSort<int>::sort(array,N);//排序
	for(int i=0;i<N;++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	
	int cnt = 0;
	int res = 0;
	for(int i = 0;i < N;++i)
	{
		//二分查找
		if((res = BinarySearch<int>::rank(-array[i],array,N)) > i)
		{
			cout << array[i] <<" with "<< array[res] <<endl;
			++cnt;
		}
	}
	cout << "Total: "<< cnt << endl;
}
