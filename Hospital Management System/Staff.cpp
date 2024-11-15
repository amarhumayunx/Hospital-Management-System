#include "Staff.h"
#include <iostream>

Staff::Staff(int id, string name, string role, string department) {
    this->id = id;
    this->name = name;
    this->role = role;
    this->department = department;
}

void Staff::display() const {
    cout << "Staff ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Role: " << role << endl;
    cout << "Department: " << department << endl;
}
