#pragma once
#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

class Staff {
public:
    int id;
    string name;
    string role;
    string department;

    Staff(int id, string name, string role, string department);
    void display() const;
};

#endif
