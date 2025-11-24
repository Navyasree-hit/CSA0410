#include <stdio.h>

int main()
{
    int frames, pages, i, j, k;
    int fault = 0, least, found;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages];
    int frame[frames];
    int counter[frames];  // To store last use time

    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames and counters
    for (i = 0; i < frames; i++)
    {
        frame[i] = -1;
        counter[i] = 0;
    }

    printf("\nLRU Page Replacement Output:\n\n");

    int time = 0;

    for (i = 0; i < pages; i++)
    {
        time++;
        printf("Processing page %d: ", pageSeq[i]);

        found = 0;

        // Check if page HIT
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pageSeq[i])
            {
                counter[j] = time;  // Update recent use time
                found = 1;
                printf("Hit  ? Frames: ");
                break;
            }
        }

        // If MISS, replace LRU page
        if (!found)
        {
            // Find empty frame first
            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pageSeq[i];
                    counter[j] = time;
                    fault++;
                    found = 1;
                    break;
                }
            }

            // No empty frame ? replace LRU
            if (!found)
            {
                least = 0;

                // find least recently used (smallest counter)
                for (j = 1; j < frames; j++)
                {
                    if (counter[j] < counter[least])
                        least = j;
                }

                frame[least] = pageSeq[i];
                counter[least] = time;
                fault++;
            }

            printf("Fault ? Frames: ");
        }

        // Print frames
        for (k = 0; k < frames; k++)
        {
            if (frame[k] == -1)
                printf("- ");
            else
                printf("%d ", frame[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}

