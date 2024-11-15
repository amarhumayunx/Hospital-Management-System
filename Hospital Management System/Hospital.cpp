#include "Hospital.h"
#include <iostream>
using namespace std;

void Hospital::addPatient(int id, string name, int age, string disease, string contact) {
    Patient newPatient(id, name, age, disease, contact);
    patients.push_back(newPatient);
}

void Hospital::addStaff(int id, string name, string role, string department) {
    Staff newStaff(id, name, role, department);
    staffMembers.push_back(newStaff);
}

void Hospital::addDoctor(int id, string name, string specialty, vector<string> availableTimes) {
    Doctor newDoctor(id, name, specialty, availableTimes);
    doctors.push_back(newDoctor);
}

void Hospital::scheduleAppointment(int patientId, int doctorId, string date, string time) {
    bool doctorFound = false;
    bool appointmentScheduled = false;

    for (const Doctor& doctor : doctors) {
        if (doctor.getDoctorId() == doctorId) {
            doctorFound = true;
            // Check if doctor is available at the requested time
            if (doctor.isAvailable(time)) {
                // Schedule appointment if doctor is available
                Appointment newAppointment(patientId, doctorId, date, time);
                appointments.push_back(newAppointment);
                appointmentScheduled = true;
                cout << "Appointment successfully scheduled with Dr. " << doctor.getName()
                    << " on " << date << " at " << time << ".\n";
                break;
            }
            else {
                cout << "Doctor " << doctor.getName() << " is not available at " << time << ". Please choose another time.\n";
                break;
            }
        }
    }

    if (!doctorFound) {
        cout << "Doctor with ID " << doctorId << " not found.\n";
    }
    if (!appointmentScheduled && doctorFound) {
        cout << "No available appointment at the requested time.\n";
    }
}

void Hospital::viewPatients() const {
    if (patients.empty()) {
        cout << "No patients available.\n";
    }
    else {
        for (const Patient& patient : patients) {
            cout << "Patient ID: " << patient.id << ",\nName: " << patient.name
                << ",\nAge: " << patient.age << ",\nDisease: " << patient.disease
                << ",\nContact: " << patient.contact << endl;
        }
    }
}

void Hospital::viewStaff() const {
    if (staffMembers.empty()) {
        cout << "No staff available.\n";
    }
    else {
        for (const Staff& staff : staffMembers) {
            cout << "Staff ID: " << staff.id << ",\nName: " << staff.name
                << ",\nRole: " << staff.role << ",\nDepartment: " << staff.department << endl;
        }
    }
}

void Hospital::viewDoctors() const {
    if (doctors.empty()) {
        cout << "No doctors available.\n";
    }
    else {
        for (const Doctor& doctor : doctors) {
            cout << "Doctor ID: " << doctor.getDoctorId() << ",\nName: " << doctor.getName()
                << ",\nSpecialty: " << doctor.getSpecialty() << ",\nAvailable Times: ";
            for (const string& time : doctor.getAvailableTimes()) {
                cout << time << " ";
            }
            cout << endl;
        }
    }
}

void Hospital::viewAppointments() const {
    if (appointments.empty()) {
        cout << "No appointments scheduled.\n";
    }
    else {
        for (const Appointment& appointment : appointments) {
            cout << "Patient ID: " << appointment.patientId << ",\nDoctor ID: " << appointment.doctorId
                << ",\nDate: " << appointment.date << ",\nTime: " << appointment.time << endl;
        }
    }
}
