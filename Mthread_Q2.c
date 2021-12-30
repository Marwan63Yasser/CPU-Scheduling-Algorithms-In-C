// Created by (--Marwan Yasser--)
// Question 2 in Multithreading Sheet

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

//#define MAX 4


//computes an element in the resultant matrix
void *multiply(void* arg)
{
	int *d = (int *)arg;
	int k = 0, i = 0;

	int x = d[0];
	for (i = 1; i <= x; i++)
		k += d[i]*d[i+x];

	int *p = (int*)malloc(sizeof(int));
		*p = k;

//Used to terminate a thread and the return value is passed as a pointer
	pthread_exit(p);
}

//Driver code
int main()
{
int m1=0,m2,m3,m4;
    printf("\nMost size of the input matrix is 10x10 !!!\n\n");

	printf("enter the number of rows in matrix 1:");
	scanf("%d", &m1);
	
	printf("enter the number of columns in matrix 1:");
	scanf("%d", &m2);
	
	printf("enter the number of rows in matrix 2:");
	scanf("%d", &m3);
	
	printf("enter the number of columns in matrix 2:");
	scanf("%d", &m4);
	
	printf("\n\n")
	
	int matrixA[10][10];
	int matrixB[10][10];


	int r1=m1,c1=m2,r2=m3,c2=m4,i,j,k;


	// matrixA
	for (i = 0; i < r1; i++)
	{
			for (j = 0; j < c1; j++)
			{
				printf("enter the value first matrix: ";
	            scanf("%d", &matrixA[i][j]);
			}
	}
	
	
	// matrixB
	for (i = 0; i < r2; i++)
	{
		
			for (j = 0; j < c2; j++)
			{
				
				printf("enter the value second matrix: ";
	            scanf("%d", &matrixB[i][j]);
			}
	}


	// matrix A display
	
	printf("the first matrix values:\n");
	
	for (i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
			printf("%d ",matrixA[i][j]);
	    printf("\n");
	}

	// matrix B display
	
	printf("the second matrix values:\n");
	
	for (i = 0; i < r2; i++){
		for(j = 0; j < c2; j++)
			printf("%d ",matrixB[i][j]);
		printf("\n");
	}


	int maxi = r1*c2;


	pthread_t *threads;
	
	threads = (pthread_t*)malloc(maxi*sizeof(pthread_t));

	int counter = 0;
	
	int* d = NULL;
	
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
			{

			d = (int *)malloc((20)*sizeof(int));
			d[0] = c1;

			for (k = 0; k < c1; k++)
				d[k+1] = matrixA[i][k];

			for (k = 0; k < r2; k++)
				d[k+c1+1] = matrixB[k][j];

				pthread_create(&threads[counter++], NULL, multiply, (void*)(d));

			}
	}

	printf("RESULT Marix IS : \n");
	
	for (i = 0; i < maxi; i++)
	{
	void *k;

	//Joining all threads 
	pthread_join(threads[i], &k);


		int *p = (int *)k;
	printf("%d ",*p);
	if ((i + 1) % c2 == 0)
		printf("\n");
	}



return 0;
}
