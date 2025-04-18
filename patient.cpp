#include "patient.h"

//constructor
patient::patient(int pat_num , int arrive_time, int wait_time , int app_length ) 
    : patient_number(pat_num), arrival_time(arrive_time), waiting_time(wait_time), appointment_length(app_length) {
}

//Destructor though empty because no dynamic memory
patient::~patient() {
}

//method to set patient info
void patient::set_patient_info(int pat_num , int arrive_time , int wait_time , int app_length ) {
    patient_number = pat_num;
    arrival_time = arrive_time;
    waiting_time = wait_time;
    appointment_length = app_length;
}


//method to return waiting time
int patient::get_waiting_time() const {
    return waiting_time;
}


//method to set the waiting time
void patient::set_waiting_time(int time) {
    waiting_time = time;
}


//method to increment the waiting time by 1
void patient::increment_waiting_time() {
    waiting_time++;
}


//Method to return the arrival time
int patient::get_arrival_time() const {
    return arrival_time;
}


//Method to return the appointment time
int patient::get_appointment_length() const {
    return appointment_length;
}


//Method to return the patient number
int patient::get_patient_number() const {
    return patient_number;
}
