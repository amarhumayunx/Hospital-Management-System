#pragma once
#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "Staff.h"
#include "Appointment.h"
#include "Doctor.h"
#include <vector>

class Hospital {
private:
    vector<Patient> patients;
    vector<Staff> staffMembers;
    vector<Appointment> appointments;
    vector<Doctor> doctors;

public:
    void addPatient(int id, string name, int age, string disease, string contact);
    void addStaff(int id, string name, string role, string department);
    void addDoctor(int id, string name, string specialty, vector<string> availableTimes);
    void scheduleAppointment(int patientId, int doctorId, string date, string time);
    void viewPatients() const;
    void viewStaff() const;
    void viewDoctors() const;
    void viewAppointments() const;
};

#endif
