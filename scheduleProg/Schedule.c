#include <stdio.h>
#include <stdbool.h>
#include "task.h"




void schedule_FCFS(Task Tab[], int n )
{

    for(int i=0;i<n; i++)
    {
        Tab[i].tid=(i+1);
    }
    printf("Running task:name, prio, burst, slice\n");
    for(int i=0;i<n;i++)
    {
        run(Tab[i], Tab[i].burst);
    }
    printf("\n");

}


void schedule_SJF(Task Tab[], int n )
{
    //sorting of burst times
    int pos;
    Task temp;
    int j;
    for(int i=0;i<n;i++)
    {
        pos=i;
        for( j=i+1;j<n;j++)
        {
            if(Tab[j].burst<Tab[pos].burst)
                pos=j;

        }

        temp=Tab[i];
        Tab[i]=Tab[pos];
        Tab[pos]=temp;


    }

    for(int i=0;i<n;i++)
    {
        run(Tab[i],Tab[i].burst);
    }

    printf("\n");


}

void schedule_Priority(Task Tab[], int n )
{
    //sorting of burst times
    int pos;
    Task temp;
    int j;
    for(int i=0;i<n;i++)
    {
        pos=i;
        for( j=i+1;j<n;j++)
        {
            if(Tab[j].priority<Tab[pos].priority)
                pos=j;
        }

        temp=Tab[i];
        Tab[i]=Tab[pos];
        Tab[pos]=temp;


    }

    for(int i=0;i<n;i++)
    {
        run(Tab[i],Tab[i].burst);
    }
    printf("\n");


}


void schedule_RR(Task Tab[], int n, int quantum )
{

    for(int i=0;i<n; i++)
    {
        Tab[i].tid=(i+1);
     }


// Function to find the waiting time for all
// processes

    // Make a copy of burst times bt[] to store remaining
    // burst times.
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = Tab[i].burst;

    int t = 0; // Current time

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > quantum)
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t += quantum;
                    //i can call the cpu fonction

                    run(Tab[i],10);

                    // Decrease the burst_time of current process
                    // by quantum
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];




                    //i can call the cpu program with slice=rem_bt[i]

                    run(Tab[i],rem_bt[i]);
                    printf("Process %s finished\n",Tab[i].name);

                    // Waiting time is current time minus time
                    // used by this process
                    Tab[i].wait_time = t - Tab[i].burst;

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (done == true)
        {
            printf("\n");
             break;

        }


    }







}

void schedule_priority_RR(Task Tab[], int n )
{

        //sorting of burst times
    int pos;
    Task temp;
    Task RR[n];
    int j;
    for(int i=0;i<n;i++)
    {
        pos=i;
        for( j=i+1;j<n;j++)
        {
            if(Tab[j].priority<Tab[pos].priority)
                pos=j;
        }

        temp=Tab[i];
        Tab[i]=Tab[pos];
        Tab[pos]=temp;



    }

    //apre le tri on va envoyerles process
     int nb=0;
    for(int i=0; i<n; i++ )
    {
        if((Tab[i].priority !=Tab[(i+1)].priority))
        {
            //call le the function CPU.c
            run(Tab[i],Tab[i].burst);
            printf("normal\n");


        }
        else
        {

            RR[0]=Tab[i];
            //RR[1]=Tab[i+1];
            nb=i+1;
            pos=1;

            while((nb<n)&&(Tab[i].priority==Tab[nb].priority) )
            {

                RR[pos]=Tab[nb];
                pos=pos+1;
                nb=nb+1;
            }
            i=nb-1;
            schedule_RR(RR, pos, 10);








            //printf("Afiche\n");



        }



    }




}



