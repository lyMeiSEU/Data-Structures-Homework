#include<iostream>
#include <time.h>
using namespace std;

static int N=0;

int BinarySearch(int *a,const int x,const int n)
{
	int left=0,right=n-1;
	N+=2;
	while(left<=right)
	{
		N++;
		int middle=(left+right)/2;
		N+=2;
		if(x<a[middle])
		{
			right=middle-1;
			N++;
		}
		else if(x>a[middle])
		{
			N++;
			left=middle-1;
		}
		else 
		{
			N++;
			return middle;
		}
	}
	return -1;
}

/******************************************
O(log(n))
n	total	runTime		n	total	runTime
0	26		0.015		65	18		0.015
25	22		0.007		75	26		0.007
35	14		0.007		85	14		0.007
45	26		0.015		95	26		0.015
55	22		0.007		100	22		0.015
******************************************/
int main()
{
	int a1[100];
	double start,stop,durationTime;
	int i;

	for(i=0;i<100;++i)
		a1[i]=i;

	start=clock();

	int n=100000;
	while(n--)
		BinarySearch(a1,50,100);

	stop = clock();

    durationTime = ((double)(stop - start)) / CLK_TCK;
	cout<<durationTime<<endl;
	cout<<N<<endl;
}