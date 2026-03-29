#include <iostream>
#include <algorithm>

using namespace std;

class info
{
private:
    int userid;
    string username;
    int mobileno;
    string address;
    float billamt;

public:
    static int qcount;
    static int mcount;
    void accept();
    void display();
    static int mergeSort(info arr[], int low, int high);
    static void merge(info arr[], int low, int mid, int high);
    static void quickSort(info arr[], int low, int high);
    static int partition(info arr[], int low, int high);
};

void info::accept()
{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter mobile no: ";
    cin >> mobileno;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter Bill Amount: ";
    cin >> billamt;
}

void info::display()
{
    cout << "\n";
    cout << "Username: " << username << endl;
    cout << "Mobile No: " << mobileno << endl;
    cout << "Address: " << address << endl;
    cout << "Bill Amount: " << billamt << endl;
    cout << "\n";
}

int info::mergeSort(info arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void info::merge(info arr[], int low, int mid, int high)
{
    mcount++;
    info b[100];

    int i = low;
    int j = mid + 1;
    int key = low;

    while (i <= mid && j <= high)
    {
        if (arr[i].username <= arr[j].username)
        {
            b[key] = arr[i];
            i++;
        }
        else
        {
            b[key] = arr[j];
            j++;
        }
        key++;
    }

    while (i <= mid)
    {
        b[key] = arr[i];
        i++;
        key++;
    }

    while (j <= high)
    {
        b[key] = arr[j];
        j++;
        key++;
    }

    for (int k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}

void info::quickSort(info arr[], int low, int high)
{
    if (high > low)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int info::partition(info arr[], int low, int high)
{
    qcount++;
    int pivot = arr[high].mobileno;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].mobileno <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int info::mcount = 0;
int info::qcount = 0;
int main()
{

    int n;
    int choice, result;
    string key;

    cout << "Enter no of records: ";
    cin >> n;
    info arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for person " << i + 1 << endl;
        arr[i].accept();
    }

    while (true)
    {
        cout << "\nChoose\n";
        cout << "1. Display All Information\n";
        cout << "2. Merge Sort\n";
        cout << "3.Quick Sort\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (n == 0)
            {
                cout << "No records to display." << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    arr[i].display();
                }
            }
            break;
        case 2:
            info::mergeSort(arr, 0, n - 1);
            cout << "Sorting Successful!\n";
            cout << "Merge Sort Passes: " << info::mcount << endl;
            break;
        case 3:
            info::quickSort(arr, 0, n - 1);
            cout << "Sorting Successful!\n";
            cout << "Quick Sort Passes: " << info::qcount << endl;
            break;

        case 4:
            cout << "Exiting" << endl;
            return 0;

        default:
            cout << "Error" << endl;
        }
    }

    return 0;
}
