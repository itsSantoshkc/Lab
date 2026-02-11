#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process
{
    int pid, AT, BT, WT, TAT;
};

struct process a[10];
int queue[100];
int front = -1, rear = -1;

void inputArrivalTime(int n, int *arrivalTime);
void inputBurstTime(int n, int *burstTime, int *p);
void swap(int *x, int *y);
void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime);
void sortingSJF(int n, int *at, int *bt, int *p);
float calculateAvgTATime(int *TATime, int n);
float calculateAvgWaitingTime(int *WaitingTime, int n);
void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p);
void SRTN(int n);
void RR(int n);
void insert(int n);
int delete();

int main()
{
    int choice;
    while (1)
    {
        printf("\nProcess scheduling algorithm: \n");
        printf("1. First Come First Serve\n");
        printf("2. Shortest Job First (non-preemptive)\n");
        printf("3. Shortest Remaining Time Next (preemptive)\n");
        printf("4. Round Robin\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Terminating program!!\n");
            break;
        }
        int n;
        printf("Enter the number of processes: ");
        scanf("%d", &n);

        int *arrivalTime = malloc(n * sizeof(int));
        int *burstTime = malloc(n * sizeof(int));
        int *waitingTime = malloc(n * sizeof(int));
        int *TATime = malloc(n * sizeof(int));
        int *Process = malloc(n * sizeof(int));

        switch (choice)
        {
        case 1:
            printf(" >>>>First Come First Serve<<<<\n");
            inputArrivalTime(n, arrivalTime);
            inputBurstTime(n, burstTime, Process);
            FCFS(n, TATime, arrivalTime, burstTime, waitingTime, Process);
            break;
        case 2:
            printf(" >>>>Shortest Job First (non-preemptive)<<<<\n");
            inputArrivalTime(n, arrivalTime);
            inputBurstTime(n, burstTime, Process);
            SJF(n, TATime, arrivalTime, burstTime, waitingTime, Process);
            break;
        case 3:
            printf(" >>>>Shortest Remaining Time Next (preemptive)<<<<\n");
            SRTN(n);
            break;
        case 4:
            printf(" >>>>Round Robin<<<<\n");
            RR(n);
            break;
        default:
            printf("Please enter correct options!\n");
            break;
        }

        free(arrivalTime);
        free(burstTime);
        free(waitingTime);
        free(TATime);
        free(Process);
    }
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void inputArrivalTime(int n, int *arrivalTime)
{
    printf("Enter the arrival times: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arrivalTime[i]);
}

void inputBurstTime(int n, int *burstTime, int *p)
{
    printf("Enter the burst times: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &burstTime[i]);
        p[i] = i + 1;
    }
}

void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrivalTime[i] > arrivalTime[j])
            {
                swap(&p[i], &p[j]);
                swap(&arrivalTime[i], &arrivalTime[j]);
                swap(&burstTime[i], &burstTime[j]);
            }
        }
    }
}

void sortingSJF(int n, int *at, int *bt, int *p)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j]))
            {
                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }
}
float calculateAvgTATime(int *TATime, int n)
{

    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += TATime[i];
    return sum / n;
}
float calculateAvgWaitingTime(int *WaitingTime, int n)
{
    float sum = 6;
    for (int i = 0; i < n; ++i)
        sum += WaitingTime[i];
    return sum / n;
}

void display(int n, int *p, int *arrival, int *burst, int *completion, int *tat, int *wt)
{
    printf("\nProcess\tArrival\tBurst\tCompletion\tTAT\tWaiting");
    for (int i = 0; i < n; i++)
    {
 tat[i] = completion[i] - arrival[i];
         wt[i] = tat[i] - burst[i];
        printf("\nP[%d]\t%d\t%d\t%d\t\t%d\t%d",
               p[i], arrival[i], burst[i], completion[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f", calculateAvgWaitingTime(wt, n));
    printf("\nAverage Turnaround Time = %.2f\n", calculateAvgTATime(tat, n));
}

void FCFS(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p)
{

    int *completionTime = malloc(n * sizeof(int));
    sortingFCFS(p, n, arrivalTime, burstTime);
    completionTime[0] = arrivalTime[0] + burstTime[0];

    for (int i = 1; i < n; i++)
    {
        if (completionTime[i - 1] < arrivalTime[i])
            completionTime[i] = arrivalTime[i] + burstTime[i];
        else
            completionTime[i] = completionTime[i - 1] + burstTime[i];
    }
 display(n,p, arrivalTime, burstTime, completionTime, TATime, waitingTime);
    free(completionTime);
}



void SJF(int n, int *TATime, int *arrivalTime, int *burstTime, int *waitingTime, int *p)
{
    int *completionTime = malloc(n * sizeof(int));
    sortingSJF(n, arrivalTime, burstTime, p);
    completionTime[0] = arrivalTime[0] + burstTime[0];

    for (int i = 1; i < n; i++)
    {
        int pos = i;
        int min = burstTime[i];
        for (int j = i; j < n && arrivalTime[j] <= completionTime[i - 1]; j++)
        {
            if (burstTime[j] < min)
            {
                min = burstTime[j];
                pos = j;
            }
        }
        swap(&p[i], &p[pos]);
        swap(&arrivalTime[i], &arrivalTime[pos]);
        swap(&burstTime[i], &burstTime[pos]);
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }
        display(n,p, arrivalTime, burstTime, completionTime, TATime, waitingTime);

    
    free(completionTime);
}


void SRTN(int n)
{
    int arrival[10], burst[10], remaining[10], completion[10];
    int time = 0, completed = 0, shortest;
    float totalWT = 0, totalTAT = 0;
    bool is_done[10] = {false};

    printf("Enter arrival times:");

    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    printf("Enter burst times: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    while (completed != n)
    {
        shortest = -1;
        int min_time = 9;
        for (int i = 0; i < n; i++)
        {
            if (!is_done[i] && arrival[i] <= time && remaining[i] < min_time && remaining[i] > 0)
            {
                min_time = remaining[i];
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            time++;
            continue;
        }
        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0)
        {
            completion[shortest] = time;
            is_done[shortest] = true;
            int tat = completion[shortest] - arrival[shortest];
            int wt = tat - burst[shortest];
            totalWT += wt;
            totalTAT += tat;
            printf("\nP[%d]\t%d\t%d\t%d\t%d\t%d", shortest + 1, arrival[shortest], burst[shortest], completion[shortest], tat, wt);
            completed++;
        }
    }
    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
}
void insert(int n)
{

    if (front == -1) 
        front = 0;

    if (rear >= 99) {
        printf("Queue overflow! Cannot insert process.\n");
        return;
    }
    
    queue[++rear] = n;
}

int delete()
{
    if (front == -1 || front > rear) {
        return -1; 
    }
    return queue[front++];
}

void RR(int n)
{
    int TQ, TIME = 0;

    int *temp_bt = malloc(n * sizeof(int)); 
    int *exist = calloc(n, sizeof(int));
    float totalWT = 0, totalTAT = 0;
    

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].AT);
        a[i].pid = i + 1;
    }

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].BT);
        temp_bt[i] = a[i].BT; 
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &TQ);

    
    front = -1;
    rear = -1;
    
    
    for(int i = 0; i < n; i++) {
        if (a[i].AT <= 0) {
            insert(i);
            exist[i] = 1;
        }
    }
    while (front <= rear)
    {
        int p_idx = delete(); 
        if (p_idx == -1) break; 
        int run_time = (a[p_idx].BT >= TQ) ? TQ : a[p_idx].BT;
        a[p_idx].BT -= run_time;
        TIME += run_time;
        for (int i = 0; i < n; i++)
        {
            if (!exist[i] && a[i].AT <= TIME)
            {
                insert(i);
                exist[i] = 1;
            }
        }        
        if (a[p_idx].BT == 0) 
        {
            a[p_idx].TAT = TIME - a[p_idx].AT;
            a[p_idx].WT = a[p_idx].TAT - temp_bt[p_idx];
            totalTAT += a[p_idx].TAT;
            totalWT += a[p_idx].WT;
        }
        else
        {
            insert(p_idx);
        }
    }
    printf("\nProcess\tArrival\tBurst\tTAT\tWaiting");
    for (int i = 0; i < n; i++)
    {
        printf("\nP[%d]\t%d\t%d\t%d\t%d", a[i].pid, a[i].AT, temp_bt[i], a[i].TAT, a[i].WT);
    }
    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    free(temp_bt);
    free(exist);
}