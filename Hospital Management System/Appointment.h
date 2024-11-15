#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
using namespace std;

class Appointment {
public:
    int patientId;
    int doctorId;
    string date;
    string time;

    Appointment(int patientId, int doctorId, string date, string time);
    void display() const;
};

#endif
