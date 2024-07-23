#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int npros;
    int i,j;
    printf(" Enter no. of processes \n ");
    scanf("%d",&npros);
    int at[npros], bt[npros];
    printf("Enter the arrival time for the following processes: \n");

    for(i=0;i<npros;i++)
    {
        printf(" Enter arrival time for %d process \n",(i+1));
        scanf("%d",&at[i]);
        printf(" Enter burst time for %d processes \n", (i+1));
        scanf("%d",&bt[i]);
    }

    printf(" \n");
    printf(" Your problem chart is:  \n");
    printf(" Process \t Arrival Time \t Burst time \t \n");

    for (i=0;i<npros;i++)
    {
        printf(" process%d \t  %d  \t\t  %d  \n",(i+1),at[i],bt[i]);    
    }

    int st[npros], ct[npros],tat[npros], wat[npros];
    st[0]=at[0];
    int stat=0;
    int swat=0;

    for (i=0;i<npros;i++)
    {
        ct[i]=st[i]+bt[i];
        st[i+1]=ct[i];
        tat[i]=ct[i]-at[i];
        wat[i]=tat[i]-bt[i];
        stat+=tat[i];
        swat+=wat[i];
    }


    int atat=stat/npros;
    int awat=swat/npros;

    printf("Average turnaround time is :%d\n",atat);
    printf("Average waiting time is :%d\n",awat);
    printf(" \n");
    printf(" GANTT CHART : \n");
    printf(" Completion time \t Turnaround time \t Waiting time \n");
    for (i=0;i<npros;i++)
    {
        printf("\t%d\t\t%d\t\t\t%d\t\t\n",ct[i],tat[i],wat[i]);
    }

    printf("\n");
    printf("Gantt chart :\n");
    printf("0 - ");

    for(i=0;i<npros;i++)
    {
        if(ct[i]<at[i+1])
        printf("Ideal state - ");
        else
        printf("P%d - %d ",(i+1),ct[i]);
    }

    printf("\n");
    return 0;
}