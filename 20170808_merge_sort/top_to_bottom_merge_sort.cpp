/*in_place_merge_sort*/ 
#include <iostream> 

/*原地归并排序*/
using namespace std;

template <typename T>
class MergeSort
{
public:
	static void sort(T* d,unsigned size);
private:
	static T* aux;
	static void sort(T* d,unsigned lo,unsigned hi);
	static void merge(T*,unsigned int lo,unsigned int mid, unsigned hi);
};

//排序公有方法
template <typename T>
void MergeSort<T>::sort(T* a,unsigned size)
{
	aux = new T[size];//建立新的辅助数组，所有的归并操作就用这一个
	sort(a,0,size-1);//排序
	delete[] aux;//释放辅助数组内存
}

template <typename T>
T* MergeSort<T>::aux = 0;

//递归排序
template <typename T>
void MergeSort<T>::sort(T* a,unsigned lo,unsigned hi)
{
	if(hi <= lo)return;//排序完成
	
	int mid = (lo + hi)/2;//将数组一分为二
	sort(a,lo,mid);//将左边进行排序
	sort(a,mid+1,hi);//右边进行排序
	merge(a,lo,mid,hi);//归并
}

//归并
template <typename T>
void MergeSort<T>::merge(T* a,unsigned int lo,unsigned int mid, unsigned hi)
{
	unsigned int i = lo , j=mid+1;
	
	for(int k = lo;k < hi+1;++k)//将源数组的数据复制到辅助数组
		aux[k] = a[k];
	
	for(int k = lo;k < hi+1;++k)
	{
		if(i > mid) a[k] = aux[j++]; //如果i超过了中间说明左半边数组已经用完
		else if(j > hi) a[k] = aux[i++];//
		else if (aux[i] > aux[j]) a[k] = aux[j++];
		else a[k] = aux[i++];
	}
}

int main()
{
	int a[11]={1,23,2,44,212,4,45,54,6,789,9};
	MergeSort<int>::sort(a,11);
	
	for(int i = 0;i<11;++i)
	{
		cout << a[i] << " ";
	}
}
