# GIKI Campus Health Portal (C++)

## 🚀 Overview
A healthcare management system built to demonstrate **Object-Oriented Programming (OOP)** principles. This system handles patient registration and records management with persistent data storage.

## 🛠️ Technical Highlights
* **Abstract Base Class:** Uses the `Person` class with a pure virtual function (`displayDetails`) to enforce polymorphism.
* **Encapsulation:** Protected and private members ensure data integrity within the `Patient` and `HealthcareSystem` classes.
* **File Persistence:** Automatically syncs patient records to `hospital_records.txt` using the `fstream` library.
* **Memory Efficiency:** Utilizes `std::vector` and `emplace_back` for optimized object construction.

## 💻 Tech Stack
* **Language:** C++
* **Concepts:** Inheritance, Virtual Functions, File I/O, I/O Manipulation (`iomanip`).

## ⚙️ How to Run
1. Compile the code:
   `g++ main.cpp -o HMS_Portal`
2. Run the application:
   `./HMS_Portal`
