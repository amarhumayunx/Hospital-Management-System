#pragma once
#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;
    string contact;

    Patient(int id, string name, int age, string disease, string contact);
    void display() const;
};

#endif
