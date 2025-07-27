#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    string course;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear newline
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Course: ";
        getline(cin, course);
    }

    void display() const {
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nName: " << name;
        cout << "\nCourse: " << course << endl;
    }
};

vector<Student> students;

void addStudent() {
    system("clear");
    Student s;
    s.input();
    students.push_back(s);
    cout << "\nStudent added successfully!" << endl;
    cin.get(); // Pause
}

void viewStudents() {
    system("clear");
    cout << "\nList of Students:\n";
    for (const auto& s : students) {
        s.display();
        cout << "----------------------\n";
    }
    cin.get(); // Pause
}

void menu() {
    int choice;
    do {
        system("clear");
        cout << "=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To catch newline after int input

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
            cin.get();
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
