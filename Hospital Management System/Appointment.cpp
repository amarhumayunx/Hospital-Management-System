#include "Appointment.h"
#include <iostream>

Appointment::Appointment(int patientId, int doctorId, string date, string time) {
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->date = date;
    this->time = time;
}

void Appointment::display() const {
    cout << "Patient ID: " << patientId << endl;
    cout << "Doctor ID: " << doctorId << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
}
