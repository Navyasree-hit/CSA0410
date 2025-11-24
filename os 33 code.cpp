#include <stdio.h>

int main()
{
    int frames, pages, i, j, k, pos, flag1, flag2;
    int fault = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int pageSeq[pages];
    int frame[frames];

    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++)
        scanf("%d", &pageSeq[i]);

    // Initialize frames as empty
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement Output:\n\n");

    for (i = 0; i < pages; i++)
    {
        flag1 = flag2 = 0;

        // Check if page is already present (HIT)
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pageSeq[i])
            {
                flag1 = flag2 = 1;  // Found (hit)
                printf("Processing page %d: Hit   ? Frames: ", pageSeq[i]);
                break;
            }
        }

        // Page MISS
        if (!flag1)
        {
            // Check for empty frame
            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pageSeq[i];
                    fault++;
                    flag2 = 1; // inserted
                    break;
                }
            }
        }

        // If no empty frame ? Optimal replacement
        if (!flag2)
        {
            int farthest = -1;
            pos = 0;

            for (j = 0; j < frames; j++)
            {
                int nextUse = -1;

                for (k = i + 1; k < pages; k++)
                {
                    if (frame[j] == pageSeq[k])
                    {
                        nextUse = k;
                        break;
                    }
                }

                if (nextUse == -1)   // NEVER used again ? best to replace
                {
                    pos = j;
                    break;
                }

                if (nextUse > farthest)
                {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frame[pos] = pageSeq[i];
            fault++;
        }

        printf("Processing page %d: Fault ? Frames: ", pageSeq[i]);

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

