/*binary_search_replicate*/ 
#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

/*基于二分查找查找有序数组中的重复键值个数*/

using namespace std;

struct Key
{
	int value;//键值
	int cnt;//重复次数
	int fiInd;//在数列中的第一个位置
	int lsInd;//在数列中的最后一个位置
};

Key rank(Key* key,const vector<int>& a,int lo,int hi);

int main()
{
	string str;
	vector<int> orderedData;
	ifstream fin;
	fin.open("..\\~TEST_DATA\\ordered_random.txt", ios::in);
	while(!fin.eof())
	{
		getline(fin,str);
		orderedData.push_back(atoi(str.c_str()));
		cout << atoi(str.c_str() ) << endl;
	}
	
	
	return 0;
	
}

//二分查找的递归形式
Key rank(Key* key,const vector<int>& a,int lo,int hi)
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
	{
		if(a[mid+1])
		{
			while()
		}
		if(a[mid-1])
	}
}
