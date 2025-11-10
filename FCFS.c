#include<stdio.h>
int n;
struct proc
{
    int at, bt, ct, tat, wt;
};

void ascending(struct proc[], int);

void main()
{    
    printf("Enter how many processes in schedule - ");
    scanf("%d", &n);
    
    float sum1 = 0, sum2 = 0;    
    struct proc P[n];
    
    for(int i = 0; i < n; i++)
    {
        printf("\nArrival time of Process %d - ",i);
        scanf("%d", &P[i].at);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("\nBurst time of Process %d - ",i);
        scanf("%d", &P[i].bt);
    }
    
    printf("\nUnsorted Table -\nProc \tAT \tBT \n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d \t%d \t%d \n", i, P[i].at, P[i].bt);
    }
    
    ascending(P, n);
    
    P[0].ct = P[0].at + P[0].bt;
    
    for(int i = 1; i < n; i++)
    {
        P[i].ct = P[i-1].ct + P[i].bt;
    }
    
    for(int i = 0; i < n; i++)
    {
        P[i].tat = P[i].ct - P[i].at;
        sum1 = sum1 + P[i].tat;
        
        P[i].wt = P[i].tat - P[i].bt;
        sum2 = sum2 + P[i].wt;
    }
    
    float avg1 = sum1 / n;
    float avg2 = sum2 / n;
    
    printf("\nAnswer Table -\nProc \tAT \tBT \tCT \tTAT \tWT \n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d \t%d \t%d \t%d \t%d \t%d \n", i, P[i].at, P[i].bt, P[i].ct, P[i].tat, P[i].wt);
    }
    
    printf("\nAverage TAT = %.2f \n", avg1);
    printf("Average WT = %.2f \n\n", avg2);
}

void ascending(struct proc P[], int n)
{
        for (int i = 0; i < n; i++) 
        {
                for (int j = 0; j < n - 1 - i; j++) 
                {
                        if (P[j].at > P[j + 1].at)
                        {
                                struct proc temp = P[j];
                                P[j] = P[j+1];
                                P[j+1] = temp;
                        }
                }
        }
}

/*printf("\nGantt Chart\n");
    
    for(int i = 0; i < n; i++)
    {
        printf("P%d|",i+1);
        while(g != ct[i])
        {
            printf("\t");
        }
    }
*/
