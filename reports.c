#include <stdio.h>
#include "hospital.h"

void reportGenerator(void)
{
    int i;
    int urgencyCount[3] = {0, 0, 0};
    float totalRevenue = 0.0;

    printf("\n========== HOSPITAL REPORT ==========\n");

    for (i = 0; i < patientCount; i++)
    {
        if (urgencyLevels[i] >= 1 &&
            urgencyLevels[i] <= 3)
        {
            urgencyCount[
                urgencyLevels[i] - 1
            ]++;
        }

        totalRevenue += finalBills[i];
    }

    printf("\nPatients by Urgency\n");
    printf("Normal   : %d\n", urgencyCount[0]);
    printf("Urgent   : %d\n", urgencyCount[1]);
    printf("Critical : %d\n", urgencyCount[2]);

    printf("\nTotal Revenue : Rs. %.2f\n",
           totalRevenue);
}
