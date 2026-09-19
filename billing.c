#include "hospital.h"

float waitingTimeCalculator(int specialtyID)
{
    float waitTime;

    waitTime =
        specialtyQueue[specialtyID] *
        consultationTimes[specialtyID];

    specialtyQueue[specialtyID]++;

    return waitTime;
}

float surchargeCalculator(float baseFee, int urgency)
{
    if (urgency == 2)
        return baseFee * 0.20;

    if (urgency == 3)
        return baseFee * 0.50;

    return 0.0;
}

float wardCostCalculator(int wardID, int days)
{
    if (wardID < 0 ||
        wardID >= NUM_WARDS ||
        days <= 0)
    {
        return 0.0;
    }

    return wardRates[wardID] * days;
}

float discountCalculator(float gross, int age)
{
    if (age < 5 || age > 65)
        return gross * 0.15;

    return 0.0;
}
void displayBill(int index)
{
    float baseFee;
    float surcharge;
    float wardCost;
    float gross;

    if (index < 0 || index >= count)
    {
        printf("Invalid patient.\n");
        return;
    }

    baseFee = specialtyFees[specialtyIDs[index]];

    surcharge =
        surchargeCalculator(
            baseFee,
            urgencyLevels[index]
        );

    wardCost =
        wardCostCalculator(
            wardIDs[index],
            admissionDays[index]
        );

    gross =
        baseFee +
        surcharge +
        wardCost;

    printf("\n========== PATIENT BILL ==========\n");

    printf("Patient Name : %s\n",
           nameOfPatients[index]);

    printf("Age          : %d\n",
           ageOfPatients[index]);

    printf("Base Fee     : Rs. %.2f\n",
           baseFee);

    printf("Surcharge    : Rs. %.2f\n",
           surcharge);

    printf("Ward Cost    : Rs. %.2f\n",
           wardCost);

    printf("Discount     : Rs. %.2f\n",
           discount[index]);

    printf("Final Bill   : Rs. %.2f\n",
           finalBill[index]);
}
