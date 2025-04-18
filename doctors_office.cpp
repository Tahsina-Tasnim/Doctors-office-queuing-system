#include "doctors_office.h"

// Constructor initializes the vector of doctors with the specified number of doctors
doctors_office::doctors_office(int num_docs) : num_doctors(num_docs) {
    doctors.resize(num_docs);
}

// Destructor also empty as no dynamic memory is allocated 
doctors_office::~doctors_office() {
}

// Method to return the ID of a free doctor, or -1 if all doctors are busy
int doctors_office::get_free_doctor_ID() const {
    for (int i = 0; i < num_doctors; ++i) {
        if (doctors[i].is_free()) {
            return i;
        }
    }
    return -1;
}

// Method to return the number of busy doctors
int doctors_office::get_number_of_busy_doctors() const {
    int busy_count = 0;
    for (const auto& doc : doctors) {
        if (!doc.is_free()) {
            busy_count++;
        }
    }
    return busy_count;
}

// Method to set a doctor as busy when they are seeing a patient with the specified appointment time
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat, int app_time) {
   if (doc_ID >= 0 && doc_ID < num_doctors) { 
    doctors[doc_ID].set_current_patient(pat);
    doctors[doc_ID].set_remaining_appointment_time(app_time);
    doctors[doc_ID].set_busy();
 }
}

// Method to set a doctor as busy when they are seeing a patient, with the patient's appointment length as the appointment time
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat) {
   if (doc_ID >= 0 && doc_ID < num_doctors) { 
    doctors[doc_ID].set_current_patient(pat);
    doctors[doc_ID].set_remaining_appointment_time();
    doctors[doc_ID].set_busy();
 }
}

// Method to update the doctors
//For each busy doctor the remaining time is reduced in their current appointment by one unit
// If the remaining appointment time becomes zero the doctor is set as free 
void doctors_office::update_doctors(int time) {
    for (int i = 0; i < num_doctors; ++i) {
        if (!doctors[i].is_free()) {
            doctors[i].decrement_remaining_appointment_time();
            if (doctors[i].get_remaining_appointment_time() == 0) {
                display_appointment_done(i, doctors[i].get_current_patient_number(), time);
                doctors[i].set_free();
            }
        }
    }
}

