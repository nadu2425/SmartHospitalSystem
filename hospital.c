#include "hospital.h"

char nameOfPatients[MAXPATIENTS][50];
int ageOfPatients[MAXPATIENTS];
int urgencyLevels[MAXPATIENTS];
int specialityIDs[MAXPATIENTS];
int wardIDs[MAXPATIENTS];
int admissionDays[MAXPATIENTS];
int bedNumbers[MAXPATIENTS];

float waitingTime[MAXPATIENTS];
float finalBill[MAXPATIENTS];
float discount[MAXPATIENTS];

int count=0;
int specialtyQueue[NUMSPECIALITIES]={0};
int bedOccupancy[NUMWARDS][MAXBEDS]={0};


