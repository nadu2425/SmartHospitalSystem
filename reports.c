#include <stdio.h>
#include "hospital.h"

void generate_performance_report(void) {
    int level1_count = 0, level2_count = 0, level3_count = 0;
    double total_revenue = 0.0;
    double total_discounts = 0.0;
    int highest_idx = -1;
    double highest_bill = -1.0;

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].urgency == 1) level1_count++;
        else if (patients[i].urgency == 2) level2_count++;
        else if (patients[i].urgency == 3) level3_count++;

        total_revenue += patients[i].final_amount;
        total_discounts += patients[i].discount;

        if (patients[i].final_amount > highest_bill) {
            highest_bill = patients[i].final_amount;
            highest_idx = i;
        }
    }

    printf("\n================ SYSTEM PERFORMANCE REPORT ================\n");
    printf("1. PATIENT REGISTRATION SUMMARY:\n");
    printf("   - Total Patients Registered : %d\n", patient_count);
    printf("   - Normal Priority (Level 1) : %d\n", level1_count);
    printf("   - Urgent Priority (Level 2) : %d\n", level2_count);
    printf("   - Critical Priority (Level 3): %d\n", level3_count);

    printf("\n2. FINANCIAL REVENUE SUMMARY:\n");
    printf("   - Total Revenue Earned     : LKR %.2f\n", total_revenue);
    printf("   - Total Discounts Granted  : LKR %.2f\n", total_discounts);

    printf("\n3. WARD BED OCCUPANCY:\n");
    for (int i = 0; i < MAX_WARDS; i++) {
        int occupied = 0;
        for (int j = 0; j < WARDS[i].capacity; j++) {
            if (bedOccupancy[i][j]) occupied++;
        }
        double percentage = ((double)occupied / WARDS[i].capacity) * 100.0;
        printf("   - %-25s : %d/%d beds occupied (%.1f%%)\n",
               WARDS[i].name, occupied, WARDS[i].capacity, percentage);
    }

    printf("\n4. HIGHEST-PAYING PATIENT:\n");
    if (highest_idx != -1) {
        printf("   - Name       : %s\n", patients[highest_idx].name);
        printf("   - Total Bill : LKR %.2f\n", patients[highest_idx].final_amount);
    } else {
        printf("   - No patients recorded yet.\n");
    }
    printf("============================================================\n");
}
