# Smart Hospital & Resource System

A C-based hospital management system developed as a university programming project.

## Features
- Patient registration
- Patient urgency management
- Specialty selection
- Waiting time calculation
- Patient billing
- Emergency surcharge calculation
- Age-based discount
- Bed allocation and occupancy checking
- Hospital reports
- Patient record file handling
- Bed status file handling

## Technologies Used
- C Programming
- GCC Compiler
- Git
- GitHub

## Project Files
- main.c - Main menu and program flow
- hospital.h - Constants, declarations and function prototypes
- hospital.c - Global data and hospital information
- patient.c - Patient registration and patient display
- billing.c - Billing and waiting time calculations
- beds.c - Bed occupancy display
- reports.c - Hospital report generation
- file_handling.c - Saving and loading data
- file_handling.h - File handling function declarations
- beds_status.txt - Stores bed status information
- patient_records.txt - Stores patient records

## Compilation
Compile the project using:
```bash
gcc -Wall -Wextra -std=c99 main.c hospital.c patient.c billing.c beds.c reports.c file_handling.c -o hospital