#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin;
    fin.open("student.txt");

    if(!fin.is_open()){
        cerr << "Error opening file" << endl;
        return 1;
    }
    string buff;
    while(!fin.eof()){
        getline(fin, buff);
        cout << buff << endl;
    }
    fin.close();
    return 0;
}