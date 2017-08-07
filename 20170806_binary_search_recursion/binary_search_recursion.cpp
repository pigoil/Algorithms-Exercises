/*binary_search_recursion*/ 
#include <iostream> 

/*二分查找算法递归版*/

using namespace std;

int rank(int key,int* a,int lo,int hi);

int main()
{
	const int N = 6;
	int array[N] = {0,12,34,56,78,90};
	cout << rank(12,array,0,N-1) << endl;//1
	cout << rank(34,array,0,N-1) << endl;//2
	cout << rank(99,array,0,N-1) << endl;//-1
}

int rank(int key,int* a,int lo,int hi)
{
	if(lo > hi)return -1;
	int mid = (hi+lo)/2;
	
	cout << "key: " << key << " ";
	cout << "lo: " << lo << " ";
	cout << "hi: " << hi << "\n";
	
	if(key < a[mid])
		return rank(key,a,lo,mid-1);
	else if(key > a[mid])
		return rank(key,a,mid+1,hi);
	else
		return mid;
}
