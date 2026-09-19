#ifndef HOSPITALH
#define HOSPITALH
#define MAXPATIENTS 100
#define NUMSPECIALITIES 4
#define NUMWARDS 4
#define MAXBEDS 20
#endif

void patientRegister(void);
float waitingTimeCalculator(int specialitID);
void displayPatients(void);
