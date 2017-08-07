#include <iostream> 

/*二分查找算法*/
/*要求被查找数组一定是有序数组*/

using namespace std;

int rank(int key,int* a,int cnt);

int main()
{
	const int N = 6;
	int array[N] = {0,12,34,56,78,90};
	cout << rank(12,array,N) << endl;//1
	cout << rank(34,array,N) << endl;//2
	cout << rank(99,array,N) << endl;//-1
}

int rank(int key,int* a,int cnt)
{
	int lo=0;
	int hi=cnt-1;
	while(lo<=hi)
	{
		int mid = (lo + hi)/2;//分半
		
		cout << "key: " << key << " ";
		cout << "lo: " << lo << " ";
		cout << "hi: " << hi << "\n";
		
		if(key < a[mid])
			hi = mid - 1;
		else if(key > a[mid])
			lo = mid + 1;
		else return mid;//返回在数列中的位置
	}
	return -1;//不存在
}
