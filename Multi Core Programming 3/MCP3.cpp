#include<iostream>
#include<omp.h>

using namespace std;

void funcA(void);
void funcB(void);

void main(void)
{
#pragma omp parallel
	{
		omp_get_thread_num();
#pragma omp sections
		{
#pragma omp section
			(void)funcA();
#pragma omp section
			(void)funcB();
		}
	}




}

void funcA(void)
{
	cout << "\nTesting Function 1 running on thread = " << omp_get_thread_num();
		
}

void funcB(void)
{
	cout << "\nTesting Function 2 in running on thread = "<< omp_get_thread_num();
}