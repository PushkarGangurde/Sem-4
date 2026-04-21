#include <iostream>
using namespace std;

#define SIZE 10

class Student {
public:
    int roll;
    string name;
    float marks;

    Student() {
        roll = -1;
        name = "";
        marks = 0;
    }
};

class HashTable {
    Student table[SIZE];

public:

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(Student s) {
        int index = hashFunction(s.roll);

        if(table[index].roll == -1) {
            table[index] = s;
        }
        else {
            // linear probing
            int i = (index + 1) % SIZE;
            while(i != index) {
                if(table[i].roll == -1) {
                    table[i] = s;
                    return;
                }
                i = (i + 1) % SIZE;
            }
            cout << "Table Full\n";
        }
    }

    void display() {
        cout << "\nHash Table:\n";
        for(int i = 0; i < SIZE; i++) {
            if(table[i].roll != -1)
                cout << i << " -> " << table[i].roll << " "
                     << table[i].name << " "
                     << table[i].marks << endl;
            else
                cout << i << " -> Empty\n";
        }
    }

    void search(int key) {
        int index = hashFunction(key);
        int i = index;

        while(table[i].roll != -1) {
            if(table[i].roll == key) {
                cout << "Found: "
                     << table[i].name << " "
                     << table[i].marks << endl;
                return;
            }
            i = (i + 1) % SIZE;
            if(i == index) break;
        }
        cout << "Record not found\n";
    }

    void modify(int key) {
        int index = hashFunction(key);
        int i = index;

        while(table[i].roll != -1) {
            if(table[i].roll == key) {
                cout << "Enter new name and marks: ";
                cin >> table[i].name >> table[i].marks;
                return;
            }
            i = (i + 1) % SIZE;
            if(i == index) break;
        }
        cout << "Record not found\n";
    }
};

int main() {
    HashTable h;
    int choice;

    do {
        cout << "\n1. Insert\n2. Display\n3. Search\n4. Modify\n5. Exit\n";
        cin >> choice;

        Student s;
        int key;

        switch(choice) {
        case 1:
            cout << "Enter Roll, Name, Marks: ";
            cin >> s.roll >> s.name >> s.marks;
            h.insert(s);
            break;

        case 2:
            h.display();
            break;

        case 3:
            cout << "Enter roll to search: ";
            cin >> key;
            h.search(key);
            break;

        case 4:
            cout << "Enter roll to modify: ";
            cin >> key;
            h.modify(key);
            break;
        }
    } while(choice != 5);

    return 0;
}