#pragma once
#include <string>
#include <vector>
using namespace std;

class Doctor {
private:
    int doctorId;
    string name;
    string specialty;
    vector<string> availableTimes;  // Vector to store available time slots

public:
    Doctor(int id, string name, string specialty, vector<string> times)
        : doctorId(id), name(name), specialty(specialty), availableTimes(times) {
    }

    int getDoctorId() const { return doctorId; }
    string getName() const { return name; }
    string getSpecialty() const { return specialty; }
    vector<string> getAvailableTimes() const { return availableTimes; }

    // Method to check if a doctor is available at a given time
    bool isAvailable(string time) const {
        for (const string& availableTime : availableTimes) {
            if (availableTime == time) {
                return true;
            }
        }
        return false;
    }
};
