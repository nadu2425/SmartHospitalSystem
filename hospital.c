#include <stdio.h>
#include "hospital.h"


const Specialty SPECIALTIES[MAX_SPECIALTIES] = {
    {1, "General Practice (OPD)", 1500.00, 15, 30},
    {2, "Paediatrics",            2500.00, 20, 20},
    {3, "Cardiology",             4500.00, 30, 12},
    {4, "Neurology",              5000.00, 30, 10}
};

const Ward WARDS[MAX_WARDS] = {
    {1, "General Ward",    3000.00, 20},
    {2, "Paediatric Ward", 6000.00, 10},
    {3, "Surgical Ward",  12000.00, 10},
    {4, "ICU (Intensive Care Unit)", 25000.00, 5}
};


int bedOccupancy[MAX_WARDS][MAX_BEDS] = {0};
Patient patients[MAX_PATIENTS];
int patient_count = 0;
int specialty_queue[MAX_SPECIALTIES] = {0};
