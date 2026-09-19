#include <stdio.h>
#include "hospital.h"

void displayBeds(void)
{
    int ward;
    int bed;

    printf("\n========== BED OCCUPANCY ==========\n");

    for (ward = 0; ward < NUMWARDS; ward++)
    {
        printf("\n%s\n", wardNames[ward]);

        for (bed = 0;
             bed < wardCapacities[ward];
             bed++)
        {
            if (bedOccupancy[ward][bed] == 0)
            {
                printf("Bed %d : Available\n",
                       bed + 1);
            }
            else
            {
                printf("Bed %d : Occupied\n",
                       bed + 1);
            }
        }
    }
}
