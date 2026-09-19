#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"
#include "file_handling.h"

int main(void) {

    load_bed_status("beds_status.txt");

    int choice;
    do {
        printf("\n=======================================================\n");
        printf("     SMART HOSPITAL RESOURCE ALLOCATION SYSTEM         \n");
        printf("=======================================================\n");
        printf("1. Register New Patient Intake & Generate Bill\n");
        printf("2. View Hospital Ward Bed Status Matrix\n");
        printf("3. Display Emergency Triage Priority Queue\n");
        printf("4. Generate Performance Reports & Analytics\n");
        printf("5. Exit System\n");
        printf("=======================================================\n");
        printf("Enter Option (1-5): ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                register_patient();
                save_bed_status("beds_status.txt");
                break;
            case 2:
                display_bed_status();
                break;
            case 3:
                if (patient_count == 0) {
                    printf("\nNo patient records available.\n");
                } else {
                    sort_patients_by_priority(patients, patient_count);
                }
                break;
            case 4:
                generate_performance_report();
                break;
            case 5:
                save_bed_status("beds_status.txt");
                printf("\nExiting System. All bed data saved successfully.\n");
                break;
            default:
                printf("\nInvalid Option! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

