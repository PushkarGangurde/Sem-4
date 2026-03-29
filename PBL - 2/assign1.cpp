    #include <iostream>
    using namespace std;

    class info{
    private:
        string username;
        long mobileno;
        string address;

    public:
        void accept();
        void display();
        static int linearSearch(info arr[], int n, string key);
        static int binarySearch_rec(info arr[], int lo, int hi, string key);
        static int binarySearch_iter(info arr[], int size, string key);
    };

    void info::accept(){
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter mobile no: ";
        cin >> mobileno;
        cout << "Enter address: ";
        cin >> address;
    }

    void info::display(){
        cout << "\n";
        cout << "Username: " << username << endl;
        cout << "Mobile No: " << mobileno << endl;
        cout << "Address: " << address << endl;
        cout << "\n";
    }

    int info::linearSearch(info arr[], int n, string key){
        for (int i = 0; i < n; i++){
            if (arr[i].username == key){
                return i;
            }
        }
        return -1;
    }

    int info::binarySearch_rec(info arr[], int lo, int hi, string key){
        if (lo > hi)
            return -1;
        int mid = lo + (hi - lo) / 2;

        if (arr[mid].username == key)
            return mid;
        else if (arr[mid].username > key)
            return binarySearch_rec(arr, lo, mid - 1, key);
        else
            return binarySearch_rec(arr, mid + 1, hi, key);
    }

    int info::binarySearch_iter(info arr[], int size, string key){
        int lo = 0, hi = size - 1;

        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if (arr[mid].username == key)
                return mid;
            else if (arr[mid].username > key)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }

    int main(){
        int n;
        int choice, result;
        string key;

        cout << "Enter no of records: ";
        cin >> n;
        info arr[n];
        for (int i = 0; i < n; i++){
            cout << "\nEnter details for person " << i + 1 << endl;
            arr[i].accept();
        }

        while (true){
            cout << "\nChoose\n";
            cout << "1. Display All Information\n";
            cout << "2. Search by Username\n";
            cout << "2. Linear Search by Username\n";
            cout << "3. Binary Search (Recursive)\n";
            cout << "4. Binary Search (Iterative)\n";
            cout << "5. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                if (n == 0){
                    cout << "No records to display." << endl;
                }
                else{
                    for (int i = 0; i < n; i++){
                        arr[i].display();
                    }
                }
                break;

            case 2:
                if (n == 0){
                    cout << "No records to search." << endl;
                }
                else{
                    cout << "Enter username to search: ";
                    cin >> key;
                    int result = info::linearSearch(arr, n, key);
                    if (result != -1){
                        cout << "Record found at position: " << result + 1 << endl;
                        arr[result].display();
                    }
                    else{
                        cout << "Record not found." << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter username to search: ";
                cin >> key;
                result = info::binarySearch_rec(arr, 0, n - 1, key);
                if (result != -1){
                    cout << "Record found\n";
                    arr[result].display();
                }
                else{
                    cout << "Record not found\n";
                }
                break;

            case 4:
                cout << "Enter username to search: ";
                cin >> key;
                result = info::binarySearch_iter(arr, n, key);
                if (result != -1)
                {
                    cout << "Record found\n";
                    arr[result].display();
                }
                else
                {
                    cout << "Record not found\n";
                }
                break;

            case 5:
                cout << "Exiting" << endl;
                return 0;

            default:
                cout << "Error" << endl;
            }
        }

        return 0;
    }