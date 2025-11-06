# 🛫 Passenger Database Management System

This project is a **Passenger Database Management System** written in **C**, developed as part of a **Procedural Programming module in 2nd year**.  
It demonstrates linked lists, file I/O, and basic data management operations in C.

---

## 🚀 Features

- Add, update, and delete passenger records
- Display all passengers or search by passport number / first name
- Generate travel statistics by region
- Save and load passenger data from a CSV file
- Print detailed reports to a text file
- Sort passengers by year of birth
- Email validation and data verification
- Fully menu-driven interface

---

## 🧭 How It Works

- The system uses a **linked list** to store passenger data dynamically.
- Each passenger has the following information:
  - Passport Number
  - First Name
  - Last Name
  - Year Born
  - Email Address
  - Travel Area (UK, Europe, Asia, America, Australia)
  - Travel Class (Economy, Premium Economy, Business, First Class)
  - Trips per Year
  - Average Duration of Trips
- Data is loaded from `passenger_data.csv` at startup and saved back on exit.
- Users interact with a **menu-driven console interface** to perform all operations.

---


## 🧩 Usage Guide

1. Compile the program using a C compiler, for example:
   ```bash
   gcc passenger_database.c -o passenger_database

