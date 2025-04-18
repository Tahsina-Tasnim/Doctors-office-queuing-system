#include "simulation.h"

//Constructor initializes simulation parameters and create doctors office 
simulation::simulation(int sim_time, int num_doctors, int appointment_time, int time_between_arrival) :
    
    sim_time(sim_time), 
    num_doctors(num_doctors), 
    appointment_time(appointment_time), 
    time_between_arrival(time_between_arrival), 
    patients_arrived(0), 
    total_wait_time(0), 
    office(num_doctors) {
}

//Destructor empty as no dynamic memory allocated 
simulation::~simulation() {
    
}

//Method to run simulation
void simulation::run_simulation() {
    for (int current_time = 0; current_time < sim_time; current_time++) {
       
       //update doctors to decrement the remaining appointment time
       office.update_doctors(current_time);
       
       //increment the waiting time of each patient in the queue
       
      if (!waiting_queue.empty()) {
        int size = waiting_queue.size();
        for (int i=0; i < size; ++i) {
            patient temp = waiting_queue.dequeue();
            temp.increment_waiting_time();
            waiting_queue.enqueue(temp);
       }
    } 
    //checks if patient has arrived
        if (has_patient_arrived(time_between_arrival)) {
            
            patient new_patient(patients_arrived, current_time, 0, appointment_time);
            waiting_queue.enqueue(new_patient);
            display_patient_arrived(patients_arrived, current_time);
            patients_arrived++;
        }

        while (!waiting_queue.empty()) {
            int free_doc_id = office.get_free_doctor_ID();
            if (free_doc_id == -1) {
                break;// no free docs, break out of the loop
            }
            patient next_patient = waiting_queue.dequeue();
            total_wait_time += next_patient.get_waiting_time();
            office.set_doctor_busy(free_doc_id, next_patient);
            display_patient_seen(free_doc_id, next_patient.get_patient_number(), current_time);
        }

        // Increment waiting time for patients in queue
        /*LQueue<patient> temp_queue;
        while (!waiting_queue.empty()) {
            patient pat = waiting_queue.dequeue();
            pat.increment_waiting_time();
            temp_queue.enqueue(pat);
        }
        waiting_queue = temp_queue;*/
    }
}

//method to return office
doctors_office& simulation::get_office() {
    return office;
}

//Method to return the waiting queue
LQueue<patient>& simulation::get_patient_queue() {
    return waiting_queue;
}

//Methid to return the total waiting time
int simulation::get_total_wait_time() {
    return total_wait_time;
}

//Method to return the number of patients arrived
int simulation::get_num_patients_arrived() {
    return patients_arrived;
}
