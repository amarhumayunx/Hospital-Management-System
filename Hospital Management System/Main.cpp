#include <iostream>
#include <Windows.h>
#include "Hospital.h"

using namespace std;

// Function to set text color
void setColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

// Function to print a fancy header
void printHeader() {
    setColor(14);  // Light Yellow
    cout << "***************************************\n";
    cout << "*   Hospital Management System       *\n";
    cout << "***************************************\n";
    setColor(15);  // White
}

// Function to display menu
void displayMenu() {
    printHeader();
    setColor(10);  // Green text color for menu options
    cout << "1. Add Patient\n";
    cout << "2. Add Staff\n";
    cout << "3. Add Doctor\n";
    cout << "4. Schedule Appointment\n";
    cout << "5. View All Patients\n";
    cout << "6. View All Staff\n";
    cout << "7. View All Doctors\n";
    cout << "8. View All Appointments\n";
    cout << "9. Exit\n";
    setColor(15);  // Reset color to white
    cout << "Please select an option (1-9): ";
}

int main() {
    Hospital hospital;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, age;
            string name, disease, contact;
            cout << "\nEnter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Disease: ";
            cin.ignore();
            getline(cin, disease);
            cout << "Enter Contact Info: ";
            getline(cin, contact);
            hospital.addPatient(id, name, age, disease, contact);
            break;
        }
        case 2: {
            int id;
            string name, role, department;
            cout << "\nEnter Staff ID: ";
            cin >> id;
            cout << "Enter Staff Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Role: ";
            getline(cin, role);
            cout << "Enter Department: ";
            getline(cin, department);
            hospital.addStaff(id, name, role, department);
            break;
        }
        case 3: {
            int id;
            string name, specialty;
            vector<string> availableTimes;
            int numSlots;
            cout << "\nEnter Doctor ID: ";
            cin >> id;
            cout << "Enter Doctor Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Doctor Specialty: ";
            getline(cin, specialty);
            cout << "Enter number of available time slots: ";
            cin >> numSlots;
            cin.ignore();
            for (int i = 0; i < numSlots; i++) {
                string timeSlot;
                cout << "Enter available time slot #" << (i + 1) << ": ";
                getline(cin, timeSlot);
                availableTimes.push_back(timeSlot);
            }
            hospital.addDoctor(id, name, specialty, availableTimes);
            break;
        }
        case 4: {
            int patientId, doctorId;
            string date, time;
            cout << "\nEnter Patient ID: ";
            cin >> patientId;
            cout << "Enter Doctor ID: ";
            cin >> doctorId;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter Time (HH:MM): ";
            cin >> time;
            hospital.scheduleAppointment(patientId, doctorId, date, time);
            break;
        }
        case 5:
            hospital.viewPatients();
            break;
        case 6:
            hospital.viewStaff();
            break;
        case 7:
            hospital.viewDoctors();
            break;
        case 8:
            hospital.viewAppointments();
            break;
        case 9:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}