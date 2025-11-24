#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int choice, id, found = 0;
    long pos;

    while (1) {
        printf("\n--- RANDOM ACCESS FILE - EMPLOYEE DETAILS ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fp = fopen("employee.dat", "ab+");
            if (!fp) {
                printf("Error opening file!\n");
                exit(1);
            }

            printf("Enter Employee ID: ");
            scanf("%d", &emp.id);
            fflush(stdin);
            printf("Enter Name: ");
            gets(emp.name);
            printf("Enter Salary: ");
            scanf("%f", &emp.salary);

            fwrite(&emp, sizeof(emp), 1, fp);
            fclose(fp);
            printf("Employee Added Successfully!\n");
            break;

        case 2:
            fp = fopen("employee.dat", "rb");
            if (!fp) {
                printf("No records found!\n");
                break;
            }

            printf("\n--- EMPLOYEE LIST ---\n");
            while (fread(&emp, sizeof(emp), 1, fp)) {
                printf("ID: %d\n", emp.id);
                printf("Name: %s\n", emp.name);
                printf("Salary: %.2f\n\n", emp.salary);
            }
            fclose(fp);
            break;

        case 3:
            fp = fopen("employee.dat", "rb");
            if (!fp) {
                printf("File not found!\n");
                break;
            }

            printf("Enter Employee ID to search: ");
            scanf("%d", &id);
            found = 0;

            while (!feof(fp)) {
                pos = ftell(fp);
                if (fread(&emp, sizeof(emp), 1, fp)) {
                    if (emp.id == id) {
                        found = 1;
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", emp.id);
                        printf("Name: %s\n", emp.name);
                        printf("Salary: %.2f\n", emp.salary);
                        break;
                    }
                }
            }

            if (!found)
                printf("Employee Not Found!\n");

            fclose(fp);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

