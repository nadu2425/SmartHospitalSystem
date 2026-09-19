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
}
