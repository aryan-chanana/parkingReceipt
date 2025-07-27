# 🅿️ Parking Receipt Generator

A command-line based Parking Management System in C that allows users to record vehicle entries, calculate parking fees based on time and vehicle type, and generate exit receipts.

---

## 🛠 Features

- Handles **entry** and **exit** of vehicles
- Categorizes vehicles:  
  - Two-Wheelers (Cycle, Scooty, Bike)  
  - Four-Wheelers (Micro, Sedan, SUV)  
  - Commercial Vehicles (Tempo, Truck, Bus)
- Dynamic **cost calculation** based on entry time and type
- Generates **entry receipts** and **exit bills**
- Stores all data using binary file handling
- Automatically deletes exited vehicles from log

---

## 🗂️ Project Structure

```
parking-receipt/
├── main.c # Main program file
├── Entry_details2.txt # Stores all vehicle entries
├── backlog.txt # Stores exit data (archived logs)
└── README.md # Project documentation
```
