#include <stdio.h>
#include "hospital.h"

void calculate_billing(Patient *p) {
    int spec_idx = p->specialty_id - 1;


    p->wait_time = specialty_queue[spec_idx] * SPECIALTIES[spec_idx].consultation_time;
    specialty_queue[spec_idx]++;


    p->base_fee = SPECIALTIES[spec_idx].base_fee;
    if (p->urgency == 1) {
        p->surcharge = 0.0;
    } else if (p->urgency == 2) {
        p->surcharge = p->base_fee * 0.20;
    } else if (p->urgency == 3) {
        p->surcharge = p->base_fee * 0.50;
    } else {
        p->surcharge = 0.0;
    }


    if (p->is_admitted && p->ward_id >= 1 && p->ward_id <= MAX_WARDS) {
        p->ward_cost = p->days_admitted * WARDS[p->ward_id - 1].daily_rate;
    } else {
        p->ward_cost = 0.0;
    }


    p->gross_total = p->base_fee + p->surcharge + p->ward_cost;


    if (p->age < 5 || p->age > 65) {
        p->discount = p->gross_total * 0.15;
    } else {
        p->discount = 0.0;
    }


    p->final_amount = p->gross_total - p->discount;
}
