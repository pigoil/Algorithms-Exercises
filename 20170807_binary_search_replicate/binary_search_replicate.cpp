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
	int begin;//在数列中的第一个位置
	int end;//在数列中的最后一个位置
};

bool rank(Key* key,const vector<int>& v,int lo,int hi);

int main()
{
	/*打开文件并读取数据到容器中*/
	string str;
	vector<int> orderedData;
	ifstream fin;
	fin.open("..\\~TEST_DATA\\ordered_random.txt", ios::in);
	while(!fin.eof())
	{
		getline(fin,str);
		orderedData.push_back(atoi(str.c_str()));
		//cout << atoi(str.c_str() ) << endl;
	}
	
	//初始化查找键值
	Key k;
	k.value = 404;
	if(rank(&k,orderedData,0,orderedData.size()))//查找到
	{
		cout << "value: " << k.value << endl;
		cout << "begin: " << k.begin << endl;
		cout << "end: " << k.end << endl; 
		cout << "cnt: " << k.cnt << endl;
	}
	else cout << k.value << " not found."<< endl;//查不到
	return 0;
	
}

//二分查找的递归形式
bool rank(Key* key,const vector<int>& v,int lo,int hi)
{
	if(lo > hi)return false;
	int mid = (hi+lo)/2;
	
 	cout << "value: " << key->value << " ";
	cout << "lo: " << lo << " ";
	cout << "hi: " << hi << "\n"; 
	
	if(key->value < v[mid])
		return rank(key,v,lo,mid-1);
	else if(key->value > v[mid])
		return rank(key,v,mid+1,hi);
	else
	{
		key->cnt = 1;
		
		key->begin = mid;//初始化头尾位置
		key->end = mid;
		
		while(v[--key->begin] == key->value)//往前找
		{
			key->cnt++;
		}
		while(v[++key->end] == key->value)//往后找
		{
			key->cnt++;
		}
		key->begin++,key->end--;//被多减了一次
		return true;//找得到
	}
}
