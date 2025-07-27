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


---

## 🚦 How It Works

1. On program start, choose:
   - **Entry** → input vehicle details
   - **Exit** → enter vehicle number to retrieve & calculate dues
2. For entry:
   - Select vehicle type and subcategory
   - Enter owner and vehicle details
   - Program stores time and calculates cost per hour
3. For exit:
   - Program finds vehicle entry
   - Calculates time difference and parking charges
   - Displays final receipt and deletes record

---

## 📊 Parking Rates

| Vehicle Type     | Subcategory | Rate (₹/hour) |
|------------------|-------------|---------------|
| Two-Wheeler      | Cycle       | ₹5            |
| Two-Wheeler      | Scooty/Bike | ₹10           |
| Four-Wheeler     | Micro       | ₹20           |
| Four-Wheeler     | Sedan       | ₹25           |
| Four-Wheeler     | SUV         | ₹30           |
| Commercial       | Tempo       | ₹15           |
| Commercial       | Truck/Bus   | ₹35           |

---

## ▶️ How to Run

### On Windows:

1. Open any C IDE (e.g., Code::Blocks, Dev-C++) or terminal.
2. Make sure the data directory exists:
   - `D:\Temp. Folder\Programming\C\ok\` (or update file paths in the code).
3. Compile and run:

```bash
gcc main.c -o parking.exe
./parking.exe
```

## 📄 License
This project is open-sourced under the MIT License.

## 👤 Author
Developed by Aryan Chanana
Inspired by the need for a simple offline vehicle parking log system.
