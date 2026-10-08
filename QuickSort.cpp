#include <iostream>
using namespace std;

const int MAX = 100;

class QuickSort {
    int arr[MAX];
    int n = 0;
    void swapVals(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swapVals(arr[i], arr[j]);
            }
        }
        swapVals(arr[i + 1], arr[high]);
        return i + 1;
    }
    void quickSort(int low, int high) {
        if (low < high) {
            int p = partition(low, high);
            quickSort(low, p - 1);
            quickSort(p + 1, high);
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
        if (n > 0) quickSort(0, n - 1);
    }
};

int main() {
    QuickSort obj;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Enter array\n2. Quick Sort\n3. Display\n4. Quit\n";
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
