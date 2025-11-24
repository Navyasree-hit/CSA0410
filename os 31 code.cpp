#include <stdio.h>

int main()
{
    int frames, pages, i, j, k, flag, fault = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages];
    int frame[frames];

    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames to -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement Output:\n");

    int index = 0; // FIFO pointer

    for (i = 0; i < pages; i++)
    {
        printf("Processing page %d: ", pageSeq[i]);

        flag = 0;

        // Check if page is already present
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pageSeq[i])
            {
                flag = 1;   // Hit
                break;
            }
        }

        // If MISS, replace using FIFO
        if (flag == 0)
        {
            frame[index] = pageSeq[i];
            index = (index + 1) % frames;  // Move in FIFO manner
            fault++;

            printf("Fault ? Frames: ");
        }
        else
        {
            printf("Hit   ? Frames: ");
        }

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

