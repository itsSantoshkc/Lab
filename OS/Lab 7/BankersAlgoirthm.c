#include <stdio.h>

int main()
{
    int num_processes, num_resources;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    // Dynamic arrays are not standard C, but this uses VLA which is fine for modern compilers
    int available[num_resources];

    printf("Enter the available resources:\n");
    for (int i = 0; i < num_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    int max[num_processes][num_resources];
    int allocation[num_processes][num_resources];
    int need[num_processes][num_resources];

    printf("Enter the maximum resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < num_resources; j++)
        {
            // *** FIX 1: Corrected index from 3 to j ***
            scanf("%d", &max[i][j]); 
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i);

        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            // Need calculation is correct
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialization of Work and Finish (correct)
    int work[num_resources];
    for (int i = 0; i < num_resources; i++)
    {
        work[i] = available[i];
    }

    int finish[num_processes];
    for (int i = 0; i < num_processes; i++)
    {
        finish[i] = 0;
    }

    int safe_sequence[num_processes];
    int num_safe = 0;

    // --- Safety Algorithm Loop (Correct Logic) ---
    while (num_safe < num_processes)
    {
        int found = 0;
        // Find a process P_i that is not finished and Need <= Work
        for (int i = 0; i < num_processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }

                // If j reached num_resources, then Need <= Work is true
                if (j == num_resources)
                {
                    // Work = Work + Allocation
                    for (int k = 0; k < num_resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[num_safe++] = i;
                    finish[i] = 1;
                    found = 1; // A process was found in this pass
                }
            }
        }

        if (!found)
        {
            printf("System is in an unsafe state\n");
            return 1;
        }
    }

    printf("System is in a safe state.\nSafe sequence: ");
    // *** FIX 2 & 3: Corrected loop start index and print format ***
    for (int i = 0; i < num_processes; i++)
    {
        printf("P%d ", safe_sequence[i]); // P%d to print the process number
    }
    printf("\n");
    return 0;
}