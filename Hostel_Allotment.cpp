#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    int roomNo;

public:
    void input() {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Room Number: ";
        cin >> roomNo;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nRoom No: " << roomNo << endl;
    }

    int getId() {
        return id;
    }
};

class Hostel {
private:
    Student students[100];
    int count = 0;

public:
    void addStudent() {
        if (count < 100) {
            students[count].input();
            count++;
            cout << "Student Added Successfully!\n";
        } else {
            cout << "Hostel is Full!\n";
        }
    }

    void displayAll() {
        if (count == 0) {
            cout << "No students found!\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                cout << "Student Found:\n";
                students[i].display();
                return;
            }
        }
        cout << "Student Not Found!\n";
    }
};

int main() {
    Hostel h;
    int choice;

    do {
        cout << "\n===== HOSTEL ALLOTMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.addStudent();
                break;
            case 2:
                h.displayAll();
                break;
            case 3:
                h.searchStudent();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
