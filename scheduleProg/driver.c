/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];
    Task Table[10];

    char *name;
    int priority;
    int burst;


    in = fopen("schedule.txt","r");
    int i=0;

    while (fgets(task,SIZE,in) != NULL) {

        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));


        // add the task to the scheduler's list of tasks
        //add(name,priority,burst);
        Table[i].name=name;
        Table[i].priority=priority;
        Table[i].burst=burst;
        i=i+1;

        free(temp);
    }

    fclose(in);


    //schedule_FCFS(Table,i);

    //schedule_Priority(Table,i);
    schedule_SJF(Table,i );
    //schedule_RR(Table,i,10);
   //schedule_priority_RR(Table,i);

    printf("Hello Boss");

    // invoke the scheduler
   // schedule();
   // call

    return 0;
}
