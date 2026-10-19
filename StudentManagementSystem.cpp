#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    float marks;
};

const int MAX_STUDENTS = 100;

void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Student list is full!\n";
        return;
    }

    cout << "Enter Student ID: ";
    cin >> students[count].id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == students[count].id) {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, students[count].name);

    cout << "Enter Course: ";
    getline(cin, students[count].course);

    cout << "Enter Marks: ";
    cin >> students[count].marks;

    count++;

    cout << "Student added successfully!\n";
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Marks: " << students[i].marks << endl;
    }
}

void searchStudent(Student students[], int count) {
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent(Student students[], int &count) {
    int deleteID;
    cout << "Enter Student ID to delete: ";
    cin >> deleteID;

    for (int i = 0; i < count; i++) {
        if (students[i].id == deleteID) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                deleteStudent(students, count);
                break;

            case 5:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}