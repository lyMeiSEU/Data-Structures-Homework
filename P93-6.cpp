#include<iostream.h>
#include<math.h>
#define Max 100;

class Polynomal
{
public:
	int exp[100];
	float coef[100];
};

float Addition(Polynomal A,int n)
{
	float counter=0.0;
	for(int i=0;i<n;++i)
	{
		counter+=pow(A.coef[i],A.exp[i]);
	}
	return counter;
}

int main()
{
	Polynomal A;
	for(int i=0;i<6;++i)
		A.exp[i]=i;

	A.coef[1]=1.0;
	A.coef[2]=2.0;
	A.coef[3]=3.0;
	A.coef[4]=4.0;
	A.coef[5]=5.0;
	A.coef[6]=6.0;
	cout<<Addition(A,6)<<endl;
	return 0;
}