#include <stdio.h>

int main() {
    char filename[50];
    int owner_r, owner_w, owner_x;
    int group_r, group_w, group_x;
    int other_r, other_w, other_x;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("\nEnter permission bits (1 = allowed, 0 = not allowed)\n");

    printf("Owner Read (r): ");  scanf("%d", &owner_r);
    printf("Owner Write (w): "); scanf("%d", &owner_w);
    printf("Owner Execute (x): "); scanf("%d", &owner_x);

    printf("Group Read (r): ");  scanf("%d", &group_r);
    printf("Group Write (w): "); scanf("%d", &group_w);
    printf("Group Execute (x): "); scanf("%d", &group_x);

    printf("Others Read (r): ");  scanf("%d", &other_r);
    printf("Others Write (w): "); scanf("%d", &other_w);
    printf("Others Execute (x): "); scanf("%d", &other_x);

    printf("\n--- Linux File Access Permissions Simulation ---\n");
    printf("File: %s\n", filename);

    printf("Permissions: ");
    printf("%c", owner_r ? 'r' : '-');
    printf("%c", owner_w ? 'w' : '-');
    printf("%c", owner_x ? 'x' : '-');

    printf("%c", group_r ? 'r' : '-');
    printf("%c", group_w ? 'w' : '-');
    printf("%c", group_x ? 'x' : '-');

    printf("%c", other_r ? 'r' : '-');
    printf("%c", other_w ? 'w' : '-');
    printf("%c", other_x ? 'x' : '-');

    printf("\n\n--- User Types in Linux ---\n");
    printf("1. Owner  - The user who created the file\n");
    printf("2. Group  - Users belonging to the file’s group\n");
    printf("3. Others - All remaining users\n");

    return 0;
}

