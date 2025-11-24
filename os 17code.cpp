#include <stdio.h>

int main()
{
    int n, m;  
    int alloc[20][20], max[20][20], avail[20];
    int need[20][20], finish[20], safeSeq[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter Maximum Requirement Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

  
    for (int i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;
    while (count < n)
    {
        int found = 0;
        for (int p = 0; p < n; p++)
        {
            if (finish[p] == 0)
            {
                
                int flag = 1;
                for (int j = 0; j < m; j++)
                {
                    if (need[p][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                
                if (flag == 1)
                {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[p][j];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nSystem is in DEADLOCK state!\n");
            return 0;
        }
    }

    
    printf("\nSystem is in SAFE STATE.\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");
    return 0;
}

