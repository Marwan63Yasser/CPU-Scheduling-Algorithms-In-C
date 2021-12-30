// Modified by (--Marwan Yasser--)

// CPU-Scheduling-Algorithm-In-C
// Round Robin Scheduling Algorithm(Pre-emptive) - with arrival time

#include<stdio.h>
#include<malloc.h>

void main()
{
    int n, i, tempn, count, terminaltime=0, initialtime, qt, flag=0, *bt, *wt, *tat, *tempbt, *at;
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);
    tempn = n;

    tempbt = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
	at = (int*)malloc(n*sizeof(int));
    
    printf("\n Enter the Quantum Time : ");
    scanf("%d", &qt);
    printf("\n Enter the burst time for each process \n\n"); 
    for(i=0; i<n; i++)
    {
        printf("P%d",i);
        printf("\n  Burst time: ");
        scanf("%d", &bt[i]);
        tempbt[i] = bt[i];
		printf("  Arrival time: ");
        scanf("%d", &at[i]);
		
        //terminaltime += bt[i];
		printf("------------------------\n");
    }

    wt[0] = 0;
    printf("\n\t GANTT CHART \n");
    printf("\n----------------------------\n");
    
    for(terminaltime=0, count=0; tempn!=0;) {
        initialtime = terminaltime;

        if(tempbt[count] <= qt && tempbt[count] > 0) 
		{
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - bt[count] - at[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if(tempbt[count] > qt) {
            tempbt[count] -= qt;
            terminaltime += qt;
        }
		
        if(tempbt[count] == 0 && flag == 1) 
		{
            tempn--;
            flag=0;
        }
		
        if(initialtime != terminaltime) 
		{
            printf(" %d\t|| P%d ||\t%d\n", initialtime, count, terminaltime);
        }
		
		
        
		if(at[count+1] <= terminaltime )
		{
            ++count;
		}
		else
		{
			if(count > 0)
			{count = 0;}
		}
			
		
    }

    printf("\n PROCESS \t ARRIVAL TIME \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", i, at[i] ,bt[i], wt[i], tat[i]);
         avgwt += wt[i];
        avgtat += tat[i]; 
    }

   
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
}