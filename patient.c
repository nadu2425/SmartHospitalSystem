#include <stdio.h>
#include "hospital.h"

void patientRegister(void){
    if (count >= MAXPATIENTS){
        printf("Maximum patient limit reached");
        return;
    }
    printf("\n========== PATIENT REGISTRATION ==========\n");

    printf("Enter patient name: ");
    scanf(" %49[^\n]", nameOfPatients[count]);

    printf("Enter age: ");
    scanf("%d", &ageOfPatients[count]);

    printf("Patient registered successfully!\n");

    count++;
    printf("Enter age: ");
    scanf("%d", &ageOfPatients[count]);

    while (ageOfPatients[count] < 0)
    {
        printf("Invalid age. Enter again: ");
        scanf("%d", &ageOfPatients[count]);
    }

    printf("\nUrgency Level\n");
    printf("1. Normal\n");
    printf("2. Urgent\n");
    printf("3. Critical\n");

    printf("Enter urgency level: ");
    scanf("%d", &urgencyLevels[count]);

    while (urgencyLevels[count] < 1 || urgencyLevels[count] > 3)
    {
        printf("Invalid urgency. Enter 1-3: ");
        scanf("%d", &urgencyLevels[count]);
    }

}
void displayPatients(void)
{
    int i;

    if (count == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }

    printf("\n========== PATIENT LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("Name : %s\n", nameOfPatients[i]);
        printf("Age  : %d\n", ageOfPatients[i]);
        printf("Urgency : %d\n", urgencyLevels[i]);
    }
}
