#include "Patient.h"
#include <iostream>

Patient::Patient(int id, string name, int age, string disease, string contact) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->disease = disease;
    this->contact = contact;
}

void Patient::display() const {
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Disease: " << disease << endl;
    cout << "Contact: " << contact << endl;
}
