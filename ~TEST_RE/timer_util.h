#include<time.h>

class Timer
{
public:
	Timer(){start = clock();}
	double elapseMsec(){return (double)(clock() - start)*1000.0/CLOCKS_PER_SEC;}
private:
	clock_t start;
};
