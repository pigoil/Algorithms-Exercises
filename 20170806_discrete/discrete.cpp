#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double myRand();
int discrete(double* a,int cnt);


int main()//利用a数组设定0~N的生成概率，然后disscrete函数根据该概率分布生成随机数1~N
{
	const int CNT =3;
	const int N = 100;
	
	double a[CNT]={0.2,0.2,0.6};
	double p[CNT]={0};
	int res=0;
	
	for(int i=0;i<N;++i)
	{
		res = discrete(a,sizeof(a));
		if(res == 0)p[0]++;
		else if(res == 1)p[1]++;
		else p[2]++;
	}
	
	cout << (double)p[0]/N << endl;
	cout << (double)p[1]/N << endl;
	cout << (double)p[2]/N << endl;
}
//生成0.0~1.0的随机数
double myRand()
{
	return (double)rand() / RAND_MAX;
}

int discrete(double* a,int cnt)
{
	double r = myRand();
	double sum = 0.0;
	for(int i=0;i<cnt;++i)
	{
		sum += a[i];
		if(sum >= r)return i;
	}
	return -1;
}
