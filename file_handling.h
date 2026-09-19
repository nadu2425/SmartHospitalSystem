#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "hospital.h"

void save_bed_status(const char *filename);
void load_bed_status(const char *filename);
void append_patient_record(const char *filename, const Patient *p);

#endif // FILE_HANDLING_H
