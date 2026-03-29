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
    void setData() {
        cout << "Enter Student ID: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin.ignore();              
        getline(cin, name); 

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "ID: " << roll
             << "\tName: " << name
             << "\tMarks: " << marks << endl;
    }

    void writeData(ofstream &outfile) {
        outfile << roll << " " << name << " " << marks << endl;
    }

    void readData(ifstream &infile) {
        infile >> roll >> name >> marks;
    }
};

int main() {

    Student s[50]; 
    int count = 0;
    int choice;

    do {
        cout << "\nMenu\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Save Students to File\n";
        cout << "4. Load Students from File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            if(count < 50) {
                s[count].setData();
                count++;
            }
            else {
                cout << "Student list full\n";
            }
            break;

        case 2:
            if(count == 0) {
                cout << "No records found\n";
            }
            else {
                cout << "\nStudent Records\n";
                for(int i = 0; i < count; i++) {
                    s[i].display();
                }
            }
            break;

        case 3:
        {
            ofstream outfile("student.txt");

            if(!outfile) {
                cout << "File error\n";
                break;
            }

            for(int i = 0; i < count; i++) {
                s[i].writeData(outfile);
            }

            outfile.close();
            cout << "Data saved to file\n";
            break;
        }

        case 4:
        {
            ifstream infile("student.txt");

            if(!infile) {
                cout << "File not found\n";
                break;
            }

            count = 0;

            // Read until file ends
            while(infile && count < 50) {
                s[count].readData(infile);
                if(infile)
                    count++;
            }

            infile.close();
            cout << "Data loaded from file\n";
            break;
        }

        case 5:
            cout << "Exiting program\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}