#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks;

public:
    // Take input from user
    void setData() {
        cout << "Enter Roll: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Write to file
    void writeData(fstream &file) {
        file << roll << " " << name << " " << marks << endl;
    }

    // Read from file
    void readData(fstream &file) {
        file >> roll >> name >> marks;
    }

    // Display
    void display() {
        cout << "Roll: " << roll
             << "\tName: " << name
             << "\tMarks: " << marks << endl;
    }
};

int main() {
    Student s[10];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Open file for writing
    fstream file("student.txt", ios::out);

    // Take input and write to file
    for(int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i+1 << endl;
        s[i].setData();
        s[i].writeData(file);
    }

    file.close();

    // Open same file for reading
    file.open("student.txt", ios::in);

    cout << "\nData read from file:\n";

    // Read and display data
    for(int i = 0; i < n; i++) {
        s[i].readData(file);
        s[i].display();
    }

    file.close();

    return 0;
}