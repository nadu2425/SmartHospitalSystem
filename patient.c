#include <stdio.h>
#include <string.h>
#include "hospital.h"

void register_patient(void) {
    if (patient_count >= MAX_PATIENTS) {
        printf("Error: Patient database is full!\n");
        return;
    }

    Patient p;
    p.id = 1001 + patient_count;

    printf("\n--- PATIENT INTAKE FORM ---\n");

    printf("Enter Patient Name: ");
    getchar();
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &p.age);

    do {
        printf("Enter Urgency Level (1 = Normal, 2 = Urgent, 3 = Critical): ");
        scanf("%d", &p.urgency);
    } while (p.urgency < 1 || p.urgency > 3);

    printf("\nSelect Specialty Specialty ID:\n");
    for (int i = 0; i < MAX_SPECIALTIES; i++) {
        printf("  %d. %s (LKR %.2f)\n", SPECIALTIES[i].id, SPECIALTIES[i].name, SPECIALTIES[i].base_fee);
    }
    do {
        printf("Choice (1-%d): ", MAX_SPECIALTIES);
        scanf("%d", &p.specialty_id);
    } while (p.specialty_id < 1 || p.specialty_id > MAX_SPECIALTIES);

    printf("\nIs Patient Admitted to Ward? (1 = Yes, 0 = No): ");
    scanf("%d", &p.is_admitted);

    if (p.is_admitted) {
        printf("\nSelect Ward ID:\n");
        for (int i = 0; i < MAX_WARDS; i++) {
            printf("  %d. %s (LKR %.2f/day)\n", WARDS[i].id, WARDS[i].name, WARDS[i].daily_rate);
        }
        do {
            printf("Choice (1-%d): ", MAX_WARDS);
            scanf("%d", &p.ward_id);
        } while (p.ward_id < 1 || p.ward_id > MAX_WARDS);

        printf("Enter Days Admitted: ");
        scanf("%d", &p.days_admitted);

        if (!allocate_bed(p.ward_id, &p.bed_number)) {
            printf("Warning: Selected Ward is full! Allocation failed. Setting to Outpatient.\n");
            p.is_admitted = 0;
            p.ward_id = 0;
            p.bed_number = 0;
            p.days_admitted = 0;
        }
    } else {
        p.ward_id = 0;
        p.bed_number = 0;
        p.days_admitted = 0;
    }


    calculate_billing(&p);


    patients[patient_count++] = p;


    display_patient_bill(&p);


    append_patient_record("patient_records.txt", &p);
}

void display_patient_bill(const Patient *p) {
    printf("\n----------------------------------------------------\n");
    printf("            SMART HOSPITAL ADMISSION & BILL         \n");
    printf("----------------------------------------------------\n");
    printf("Patient ID             : PAT-%d\n", p->id);
    printf("Patient Name           : %s\n", p->name);

    if (p->age < 5 || p->age > 65) {
        printf("Age                    : %d Years (15%% Subsidy Eligible)\n", p->age);
    } else {
        printf("Age                    : %d Years\n", p->age);
    }

    printf("Specialty              : %s\n", SPECIALTIES[p->specialty_id - 1].name);

    if (p->is_admitted) {
        printf("Assigned Ward          : %s (Bed #%02d)\n", WARDS[p->ward_id - 1].name, p->bed_number);
    } else {
        printf("Assigned Ward          : None (Outpatient / OPD)\n");
    }

    char *urgency_str = (p->urgency == 3) ? "Level 3 (Critical)" :
                        (p->urgency == 2) ? "Level 2 (Urgent)" : "Level 1 (Normal)";
    printf("Urgency Level          : %s\n", urgency_str);

    printf("Base Consultation Fee  : LKR %10.2f\n", p->base_fee);

    if (p->urgency == 3) {
        printf("Emergency Surcharge    : LKR %10.2f (50%%)\n", p->surcharge);
    } else if (p->urgency == 2) {
        printf("Emergency Surcharge    : LKR %10.2f (20%%)\n", p->surcharge);
    } else {
        printf("Emergency Surcharge    : LKR %10.2f (0%%)\n", p->surcharge);
    }

    if (p->is_admitted) {
        printf("Ward Stay Cost (%d Days): LKR %10.2f\n", p->days_admitted, p->ward_cost);
    } else {
        printf("Ward Stay Cost         : LKR       0.00\n");
    }

    printf("Gross Total Bill       : LKR %10.2f\n", p->gross_total);
    printf("Age Subsidy Discount   : LKR -%9.2f\n", p->discount);
    printf("Final Payable Amount   : LKR %10.2f\n", p->final_amount);

    if (p->urgency == 3) {
        printf("Estimated Waiting Time : 0.00 mins (Immediate Attention)\n");
    } else {
        printf("Estimated Waiting Time : %.2f mins\n", p->wait_time);
    }
    printf("----------------------------------------------------\n");
}

void sort_patients_by_priority(Patient p_arr[], int count) {
        for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (p_arr[j].urgency < p_arr[j + 1].urgency) {
                Patient temp = p_arr[j];
                p_arr[j] = p_arr[j + 1];
                p_arr[j + 1] = temp;
            }
        }
    }

    printf("\n================ EMERGENCY TRIAGE QUEUE (PRIORITY ORDER) ================\n");
    for (int i = 0; i < count; i++) {
        printf("Priority %d | PAT-%d | Name: %-20s | Urgency: Level %d | Specialty: %s\n",
               i + 1, p_arr[i].id, p_arr[i].name, p_arr[i].urgency, SPECIALTIES[p_arr[i].specialty_id - 1].name);
    }
    printf("=========================================================================\n");
}
