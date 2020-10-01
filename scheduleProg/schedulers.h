#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();
void schedule_FCFS(Task Tab[], int n );
void Execute_and_findWaitingTime(Task processes[], int n, int quantum);
void schedule_Priority(Task Tab[], int n );
void schedule_SJF(Task Tab[], int n );

