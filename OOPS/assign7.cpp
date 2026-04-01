#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> grades;
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    float value;

    // Input grades
    cout << "Enter grades:\n";
    for(int i = 0; i < n; i++) {
        cin >> value;
        grades.push_back(value);   // Add element to vector
    }

    // Iterator declaration
    vector<float>::iterator it;

    float sum = 0;

    // Calculate sum using iterator
    for(it = grades.begin(); it != grades.end(); it++) {
        sum += *it;
    }

    float avg = sum / grades.size();

    // Initialize min and max
    float min = grades[0];
    float max = grades[0];

    // Find min and max using iterator
    for(it = grades.begin(); it != grades.end(); it++) {
        if(*it < min)
            min = *it;

        if(*it > max)
            max = *it;
    }

    // Display results
    cout << "\nAverage Grade: " << avg << endl;
    cout << "Minimum Grade: " << min << endl;
    cout << "Maximum Grade: " << max << endl;

    return 0;
}