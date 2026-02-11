#include <stdio.h>

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10];
    int flag1, flag2, flag3, i, j, k, pos, max, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
        frames[i] = -1;

    printf("\nPage Replacement Process (Optimal):\n");

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = flag3 = 0;

        // Check if page already exists
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not in frame
        if (flag1 == 0) {
            // Check for empty slot
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    faults++;
                    flag2 = 1;
                    break;
                }
            }

            // If no empty slot -> apply Optimal replacement
            if (flag2 == 0) {
                for (j = 0; j < no_of_frames; ++j) {
                    temp[j] = -1;
                    for (k = i + 1; k < no_of_pages; ++k) {
                        if (frames[j] == pages[k]) {
                            temp[j] = k;
                            break;
                        }
                    }
                }

                // Pick frame with farthest future use
                for (j = 0; j < no_of_frames; ++j) {
                    if (temp[j] == -1) {
                        pos = j;
                        flag3 = 1;
                        break;
                    }
                }

                if (flag3 == 0) {
                    max = temp[0];
                    pos = 0;
                    for (j = 1; j < no_of_frames; ++j) {
                        if (temp[j] > max) {
                            max = temp[j];
                            pos = j;
                        }
                    }
                }

                frames[pos] = pages[i];
                faults++;
            }
        }

        printf("Page %d -> ", pages[i]);
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
