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
