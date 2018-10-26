
#include<string>
#include<iostream>
using namespace std;

int main()
{
	int m, p;
	cout << "Please enter the size of maze" << endl;
	cin >> m >> p;
	cout << "Creating maze..." << endl;
	int **A = new int *[m];
	for (int b = 0; b < m; ++b)
		A[b] = new int[p];
	A[0][0] = 1;
	cout << "Finding the maximun path..." << endl;
	int counter = 0;
	for (int j = 0; j < p; ++j)
	{
		if (j % 4 == 0 || j % 4 == 2)
		{
			if (j == p - 2)
				counter++;
			else
				counter += m;
			for (int k = 0; k < m; ++k)
			{
				A[k][j] = 0;
			}
		}

		if (j % 4 == 1)
		{
			for (int l = 0; l < m; ++l)
				A[l][j] = 1;
			A[m-1][j] = 0;
			counter++;
		}
		if (j % 4 == 3)
		{
			counter++;
			for (int o = 1; o < m; ++o)
				A[o][j] = 1;
			A[0][j] = 0;
		}
	}
	A[m-1][p-1] = 0;
	for (int d = 0; d < m; ++d)
	{
		for (int s = 0; s < p; ++s)
		{
			cout << A[d][s] << " ";
		}
		cout << endl;
	}
	cout << "The length of path is:" << counter << endl;
	for (int v = 0; v < m; ++v)
		delete[]A[v];
	A = NULL;
	return 0;
}