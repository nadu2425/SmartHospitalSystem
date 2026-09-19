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
