#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_SPECIALTIES 4
#define MAX_WARDS 4
#define MAX_PATIENTS 100
#define MAX_BEDS 20


typedef struct {
    int id;
    char name[50];
    double base_fee;
    int consultation_time; // in minutes
    int daily_cap;
} Specialty;

typedef struct {
    int id;
    char name[50];
    double daily_rate;
    int capacity;
} Ward;


typedef struct {
    int id;
    char name[50];
    int age;
    int urgency;
    int specialty_id;
    int is_admitted;
    int ward_id;
    int bed_number;
    int days_admitted;
    double base_fee;
    double surcharge;
    double ward_cost;
    double gross_total;
    double discount;
    double final_amount;
    double wait_time;
} Patient;


extern const Specialty SPECIALTIES[MAX_SPECIALTIES];
extern const Ward WARDS[MAX_WARDS];


extern int bedOccupancy[MAX_WARDS][MAX_BEDS];
extern Patient patients[MAX_PATIENTS];
extern int patient_count;
extern int specialty_queue[MAX_SPECIALTIES];




void init_beds(void);
void display_bed_status(void);
int allocate_bed(int ward_id, int *bed_num);
void free_bed(int ward_id, int bed_num);


void register_patient(void);
void display_patient_bill(const Patient *p);
void sort_patients_by_priority(Patient p_arr[], int count);


void calculate_billing(Patient *p);


void generate_performance_report(void);


void save_bed_status(const char *filename);
void load_bed_status(const char *filename);
void append_patient_record(const char *filename, const Patient *p);

#endif // HOSPITAL_H
