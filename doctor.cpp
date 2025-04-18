#include "doctor.h"

// Constructor initializes the doctor as not busy with zero remaining appointment time
doctor::doctor() : is_busy(false), remaining_appointment_time(0) {
}

// Destructor again empty as no dynamic memory
doctor::~doctor() {
}

// Method to check if the doctor is free
bool doctor::is_free() const {
    return !is_busy;
}

// Method to set the doctor as busy
void doctor::set_busy() {
    is_busy = true;
}

// Method to set the doctor as free
void doctor::set_free() {
    is_busy = false;
}

// Method to set the remaining appointment time directly
void doctor::set_remaining_appointment_time(int t) {
    remaining_appointment_time = t;
}

// Method to set the remaining appointment time based on the current patient's appointment length
void doctor::set_remaining_appointment_time() {
    remaining_appointment_time = current_patient.get_appointment_length();
}

// Method to get the remaining appointment time
int doctor::get_remaining_appointment_time() const {
    return remaining_appointment_time;
}

// Method to decrement the remaining appointment time by one unit if greater than zero
void doctor::decrement_remaining_appointment_time() {
    if (remaining_appointment_time > 0) {
        remaining_appointment_time--;
    }
    // Check if the remaining appointment time has reached zero to set the doctor as free
    if (remaining_appointment_time == 0) {
        set_free();
    }
}

// Method to set the current patient
void doctor::set_current_patient(const patient& pat) {
    current_patient = pat;
}

// Method to get the current patient's number
int doctor::get_current_patient_number() const {
    return current_patient.get_patient_number();
}

// Method to get the current patient's arrival time
int doctor::get_current_patient_arrival_time() const {
    return current_patient.get_arrival_time();
}

// Method to get the current patient's waiting time
int doctor::get_current_patient_waiting_time() const {
    return current_patient.get_waiting_time();
}

// Method to get the current patient's appointment length
int doctor::get_current_patient_appointment_length() const {
    return current_patient.get_appointment_length();
}
