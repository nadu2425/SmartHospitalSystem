#include <stdio.h>
#include "hospital.h"
#include "file_handling.h"

void save_bed_status(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file %s for writing!\n", filename);
        return;
    }

    for (int i = 0; i < MAX_WARDS; i++) {
        for (int j = 0; j < MAX_BEDS; j++) {
            fprintf(fp, "%d ", bedOccupancy[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void load_bed_status(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return;
    }

    for (int i = 0; i < MAX_WARDS; i++) {
        for (int j = 0; j < MAX_BEDS; j++) {
            if (fscanf(fp, "%d", &bedOccupancy[i][j]) != 1) {
                bedOccupancy[i][j] = 0;
            }
        }
    }

    fclose(fp);
}

void append_patient_record(const char *filename, const Patient *p) {
    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error: Unable to open file %s for logging!\n", filename);
        return;
    }

    fprintf(fp, "PAT-%d | Name: %s | Age: %d | Urgency: %d | Specialty: %d | Admitted: %d | Ward: %d | Bed: %d | Final Bill: LKR %.2f\n",
            p->id, p->name, p->age, p->urgency, p->specialty_id, p->is_admitted, p->ward_id, p->bed_number, p->final_amount);

    fclose(fp);
}
