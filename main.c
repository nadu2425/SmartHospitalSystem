#include <stdio.h>
#include "hospital.h"


int main(void)
{
    int choice;
    int patientNumber;


    /* Load saved bed information */

    loadBeds();


    printf("\n");
    printf("========================================\n");
    printf("   SMART HOSPITAL & RESOURCE SYSTEM\n");
    printf("========================================\n");


    do
    {
        printf("\n========== MAIN MENU ==========\n");

        printf("1. Register Patient\n");
        printf("2. Display Patient Bill\n");
        printf("3. Display All Patients\n");
        printf("4. Display Bed Occupancy\n");
        printf("5. Generate Hospital Report\n");
        printf("6. Save Data\n");
        printf("7. Exit\n");

        printf("===============================\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                registerPatient();

                break;


            case 2:

                if (count == 0)
                {
                    printf(
                        "\nNo patients registered.\n"
                    );
                }
                else
                {
                    printf(
                        "\nEnter patient number (1-%d): ",
                        count
                    );

                    scanf(
                        "%d",
                        &patientNumber
                    );


                    if (patientNumber >= 1 &&
                        patientNumber <= count)
                    {
                        displayBill(
                            patientNumber - 1
                        );
                    }
                    else
                    {
                        printf(
                            "Invalid patient number.\n"
                        );
                    }
                }

                break;


            case 3:

                displayPatients();

                break;


            case 4:

                displayBeds();

                break;


            case 5:

                generateReport();

                break;


            case 6:

                saveBeds();

                savePatientRecords();

                printf(
                    "\nData saved successfully.\n"
                );

                break;


            case 7:

                saveBeds();

                savePatientRecords();

                printf(
                    "\nData saved.\n"
                );

                printf(
                    "Thank you for using Smart Hospital System.\n"
                );

                break;


            default:

                printf(
                    "\nInvalid choice. Enter 1-7.\n"
                );
        }


    } while (choice != 7);


    return 0;
}
