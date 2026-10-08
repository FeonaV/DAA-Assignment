#include <iostream>
using namespace std;

const int MAX = 100;

class InsertionSort {
    int arr[MAX];
    int n = 0;
    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
public:
    void readArray() {
        cout << "Enter number of elements: ";
        cin >> n;
        if (n < 0 || n > MAX) {
            cout << "Invalid size. Maximum is " << MAX << ".\n";
            n = 0;
            return;
        }
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
    }
    void display() const {
        if (n == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    void sortArray() {
        insertionSort();
    }
};

int main() {
    InsertionSort obj;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Enter array\n2. Insertion Sort\n3. Display\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
        case 1:
            obj.readArray();
            break;
        case 2:
            obj.sortArray();
            cout << "Array sorted.\n";
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
