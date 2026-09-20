#include <stdio.h>
#include "hospital.h"

void init_beds(void) {
    for (int i = 0; i < MAX_WARDS; i++) {
        for (int j = 0; j < MAX_BEDS; j++) {
            bedOccupancy[i][j] = 0;
        }
    }
}

void display_bed_status(void) {
    printf("\n================ HOSPITAL WARD BED STATUS ================\n");
    for (int i = 0; i < MAX_WARDS; i++) {
        printf("\n%s (Capacity: %d Beds)\n", WARDS[i].name, WARDS[i].capacity);
        printf("Bed Matrix: ");
        for (int j = 0; j < WARDS[i].capacity; j++) {
            printf("[%s] ", bedOccupancy[i][j] ? "X" : "0");
        }
        printf("\n");
    }
    printf("==========================================================\n");
}

int allocate_bed(int ward_id, int *bed_num) {
    int w_idx = ward_id - 1;
    if (w_idx < 0 || w_idx >= MAX_WARDS) return 0;

    for (int j = 0; j < WARDS[w_idx].capacity; j++) {
        if (bedOccupancy[w_idx][j] == 0) {
            bedOccupancy[w_idx][j] = 1;
            *bed_num = j + 1;
            return 1;
        }
    }
    return 0;
}

void free_bed(int ward_id, int bed_num) {
    int w_idx = ward_id - 1;
    int b_idx = bed_num - 1;
    if (w_idx >= 0 && w_idx < MAX_WARDS && b_idx >= 0 && b_idx < WARDS[w_idx].capacity) {
        bedOccupancy[w_idx][b_idx] = 0;
    }
}
