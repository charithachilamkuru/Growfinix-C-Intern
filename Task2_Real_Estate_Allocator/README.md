# 🏠 Task 2: Dynamic Real Estate Data Allocator

## 📌 Objective
This project demonstrates the use of **pointers and dynamic memory allocation in C**.  
The program allows users to manage a list of real estate properties dynamically using `malloc`, `realloc`, and `free`.

---

## 🛠 Tech Stack
- C Programming
- Pointers
- Dynamic Memory Allocation (`malloc`, `realloc`, `free`)
- Standard Libraries (`stdio.h`, `stdlib.h`)

---

## 📋 Features
- ➕ Add new property details
- 📖 View all stored properties
- 🔄 Dynamically resize memory as data grows
- 🧹 Proper memory cleanup using `free()`

---

## 🧱 Structure Used

```c
struct Property {
    int id;
    float price;
    int sqft;
};
