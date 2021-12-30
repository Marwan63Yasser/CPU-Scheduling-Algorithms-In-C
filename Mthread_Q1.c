// Created by (--Marwan Yasser--)
// Question 1 in Multithreading Sheet

#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>

int summation = 0 ;

void* thread_code ( void * param )
{ 

 int min=1 , max=10 ;  
 
 srand(time(0));
 summation= summation + ( (rand() % (max - min +1 )) + min );

}


int main ()
{
	
pthread_t thread[5];

for ( int i =0 ; i<5 ; i++)
{
pthread_create( &thread[i], 0,thread_code,0 );
}

for (int i = 0; i<5; i++)
{
pthread_join (thread[i],0);
}

printf("The summation is = %d ", summation);

}
