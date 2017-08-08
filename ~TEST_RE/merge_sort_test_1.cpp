#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include "../20170808_merge_sort/top_to_bottom_merge_sort.h"
#include "timer_util.h"

using namespace std;

int main()
{
	const int N = 10000;
	int array[N];
	string str;
	ifstream fin;
	fin.open("..\\~TEST_DATA\\disordered_random_double.txt", ios::in);
	for(int i = 0;i<N;++i)
	{
		getline(fin,str);
		array[i] = atoi(str.c_str());
		//cout << atoi(str.c_str() ) << endl;
	}
	cout << "OK" << endl;
	
	Timer t;
	MergeSort<int>::sort(array,N);
	cout << t.elapseMsec() <<endl;	
	
	//for(int i = 0;i<N;++i)
	//	cout << array[i] << endl;

}
