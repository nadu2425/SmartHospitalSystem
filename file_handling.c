#include <stdio.h>
#include "hospital.h"
#include "file_handling.h"

void saveBeds(void)
{
    FILE *file;
    int ward;
    int bed;

    file = fopen("beds_status.txt", "w");

    if (file == NULL)
    {
        printf("Error opening beds_status.txt\n");
        return;
    }

    for (ward = 0; ward < NUMWARDS; ward++)
    {
        for (bed = 0;
             bed < wardCapacities[ward];
             bed++)
        {
            fprintf(
                file,
                "%d %d %d\n",
                ward,
                bed,
                bedOccupancy[ward][bed]
            );
        }
    }

    fclose(file);
}

void loadBeds(void)
{
    FILE *file;
    int ward;
    int bed;
    int status;

    file = fopen("beds_status.txt", "r");

    if (file == NULL)
        return;

    while (
        fscanf(
            file,
            "%d %d %d",
            &ward,
            &bed,
            &status
        ) == 3
    )
    {
        if (ward >= 0 &&
            ward < NUMWARDS &&
            bed >= 0 &&
            bed < wardCapacities[ward])
        {
            bedOccupancy[ward][bed] = status;
        }
    }

    fclose(file);
}
