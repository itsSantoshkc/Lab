#include <stdio.h>
int main()
{

    int i, j = 0, n, a[50], frame[10], no, k, avail, count = 0;

    printf("\nEnter the number of pages: ");
    scanf("%d", &n);

    printf("\nEnter page numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter number of frames: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; i++)
    {
        avail = 0;
        // Check if page already exists in frame
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                avail = 1;
                break;
            }
        }

        if (avail == 0)
        { // Page fault occurs
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            // Print current frame contents
            printf("Page %d -> ", a[i]);
            for (k = 0; k < no; k++)
            {
                if (frame[k] != -1)
                {
                    printf("%d", frame[k]);
                }
                else
                {
                    printf("- ");
                }
            }
            printf("\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", count);
    return 0;
}