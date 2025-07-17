# **🎓 University_Management_System**
This University Management System (UMS) is a console-based C++ project that demonstrates core programming fundamentals and beginner-level object-oriented programming (OOP) concepts. It allows Admin and Students to interact with the system for tasks like grading, attendance, course registration, and more.


## **🔧 Features**
### **👨‍🏫 Admin Panel:**
- Secure login with credentials

- Grade students in specific courses

- Mark student attendance

- Add and drop courses

- Exit back to the main portal

### **🎓 Student Portal: **
- Sign up and login system

- View grades and attendance

- View and drop enrolled courses

- Generate course-wise report (with option to save/load to file)

## **💡 Programming Concepts Used**
Concept	Description:
Functions -	Modular code using reusable functions for login, options, reports, etc.
Structs -	Custom data types (StudentData, Course) to organize related data
Arrays -	Static arrays to store student credentials, grades, and attendance
File Handling -	Save and load student reports using ofstream and ifstream
OOP Basics - Demonstrates abstraction, modularity, and use of user-defined types
Control Flow - Usage of switch, if-else, while, and do-while loops
Input Validation - Multiple login attempts, course existence checks, etc.
Encapsulation - (Partial)	Operations like grading and attendance are grouped functionally

## **📁 File Structure**
main.cpp: The main driver code with Admin/Student interface

functions.h: Header file containing declarations, constants, and structs

functions.cpp: Implementation of all UMS features

data.txt: Output file (used for saving student reports)


#### **📌 Note **
This project is made to practice logic building and C++ syntax. It uses static arrays and does not include advanced data structures or persistent databases. Future enhancements could involve using vectors, OOP classes, or JSON-based data storage.

