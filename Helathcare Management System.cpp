#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Base Class: Demonstrating Encapsulation
class Person {
protected:
    string name;
    int age;
    string id;

public:
    Person(string n, int a, string i) : name(n), age(a), id(i) {}
    virtual void displayDetails() const = 0; // Pure virtual function for Polymorphism
    virtual ~Person() {}
};

// Derived Class: Patient
class Patient : public Person {
private:
    string ailment;

public:
    Patient(string n, int a, string i, string ail) : Person(n, a, i), ailment(ail) {}

    void displayDetails() const override {
        cout << left << setw(15) << id << setw(20) << name 
             << setw(10) << age << setw(20) << ailment << endl;
    }

    string getSaveString() const {
        return id + "," + name + "," + to_string(age) + "," + ailment;
    }
};

// HMS Controller Class
class HealthcareSystem {
private:
    vector<Patient> patients;
    const string fileName = "hospital_records.txt";

public:
    void addPatient() {
        string name, id, ailment;
        int age;

        cout << "\nEnter Patient ID: "; cin >> id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cout << "Enter Ailment: "; cin.ignore(); getline(cin, ailment);

        patients.emplace_back(name, age, id, ailment);
        saveToFile();
        cout << "\n[Success] Patient record added and synced to database.\n";
    }

    void displayAll() const {
        if (patients.empty()) {
            cout << "\nNo records found.\n";
            return;
        }
        cout << "\n--- Hospital Records ---\n";
        cout << left << setw(15) << "ID" << setw(20) << "Name" 
             << setw(10) << "Age" << setw(20) << "Ailment" << endl;
        cout << string(65, '-') << endl;
        for (const auto& p : patients) p.displayDetails();
    }

    void saveToFile() {
        ofstream outFile(fileName);
        for (const auto& p : patients) {
            outFile << p.getSaveString() << endl;
        }
        outFile.close();
    }
};

int main() {
    HealthcareSystem hms;
    int choice;

    do {
        cout << "\n--- GIKI Campus Health Portal ---";
        cout << "\n1. Add Patient Record";
        cout << "\n2. View All Records";
        cout << "\n3. Exit";
        cout << "\nSelect Option: ";
        cin >> choice;

        switch (choice) {
            case 1: hms.addPatient(); break;
            case 2: hms.displayAll(); break;
            case 3: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}