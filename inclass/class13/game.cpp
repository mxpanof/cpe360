#include <iostream>
#include <time.h>
#include <stdlib.h>
#define MAX 5
using namespace std;

int main (int argc, char const* argv[])
{
	int A[MAX][MAX], random;
	srand(time(NULL));
	cout << "A:\n";
	for (unsigned int i = 0; i < MAX; i += 1)
	{
		for (unsigned int j = 0; j < MAX; j += 1)
		{
			random = rand()%100 +1;
			if (random <= 5) 
				A[i][j] = 1;
			else 
				A[i][j]= 0;
				cout << A[i][j] << " ";
		}
		cout << "\n";
	}	
	cout << "B:\n";
	int B[MAX][MAX];
	for (unsigned int i = 0; i < MAX; i += 1)
	{
		for (unsigned int j = 0; j < MAX; j += 1)
		{
			random = rand()%100 +1;
			if (random <= 5) 
				B[i][j] = 1;
			else 
				B[i][j]= 0;
				cout << B[i][j] << " ";
		}
		cout << "\n";
	}	
	cout << "C:\n";
	int C[MAX][MAX];
	srand(time(NULL));
	for (unsigned int i = 0; i < MAX; i += 1)
	{
		for (unsigned int j = 0; j < MAX; j += 1)
		{
			C[i][j] = A[i][j] + B[i][j];
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}	
}
