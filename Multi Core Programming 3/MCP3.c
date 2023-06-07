#include<stdio.h>
#include<omp.h>


void funcA(void);
void funcB(void);


void main(void)
{
	/*omp_get_num_threads(2);*/
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			(void)funcA();
#pragma omp section
			(void)funcB();
		}
	}




}

void funcA (void)
{
	printf("Testing Function 1 %d\n",omp_get_thread_num());

}

void funcB (void)
{
	printf("Testing Function 2 %d\n",omp_get_thread_num());
}