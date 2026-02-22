# 🎓 Student Management System (C)

A **menu-driven Student Management System** developed in **C language** using **structures** and **binary file handling**.

This project simulates a basic database system where student records can be stored, retrieved, modified, and deleted permanently using file operations.

---

## 🚀 Features

* ✅ Add New Student
* 🔍 Search Student by Roll Number
* 📋 Display All Students in Table View
* ✏️ Update Student Record
* 🗑️ Delete Student Record
* 💾 Persistent Data Storage using Binary Files

---

## 🧠 Concepts Demonstrated

* Structures (`struct`)
* File Handling (`fopen`, `fread`, `fwrite`)
* Binary File Storage
* CRUD Operations
* Menu-Driven Programming
* Input Buffer Handling
* String Processing (`fgets`, `strcspn`)
* Formatted Console Output

---

## 📂 Project Structure

```
Student_Management_System/
│
├── main.c
├── data/
│   └── student.dat   (generated automatically)
├── .gitignore
└── README.md
```

---

## ⚙️ Compilation & Execution

### Compile

```
gcc main.c -o student
```

### Run (Linux / Mac)

```
./student
```

### Run (Windows)

```
student.exe
```

---

## 🖥️ Program Menu

```
1. Add New Student
2. Search Student
3. Display All Students
4. Update Student
5. Delete Student
6. Exit
```

---

## 💾 Data Storage

All student records are saved inside:

```
data/student.dat
```

Binary storage provides:

* Fast read/write operations
* Direct structure storage
* Persistent data after program exit

---

## 📊 Student Structure

```c
struct student {
    int roll_no;
    char name[25];
    char fname[25];
    int age;
    float marks;
};
```

---

## 🎯 Learning Outcomes

Through this project, I learned:

* Designing real-world console applications
* Managing structured data using files
* Implementing CRUD operations
* Handling user input safely
* Organizing a complete C project

---

## 🔮 Future Improvements

* Student login system
* Sorting students by marks
* GPA/Grade calculation
* CSV export support
* Colored terminal interface
* C++ OOP version of the system

---

## 👨‍💻 Author

**Sahdev Agarwal**

---

⭐ If you found this project useful, consider starring the repository!
