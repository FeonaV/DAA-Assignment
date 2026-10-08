#include <iostream>
using namespace std;

const int MAX = 100;

class HeapSort {
    int arr[MAX];
    int n = 0;
    void swapVals(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    void heapify(int size, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swapVals(arr[i], arr[largest]);
            heapify(size, largest);
        }
    }
    void heapSort() {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
        for (int i = n - 1; i > 0; i--) {
            swapVals(arr[0], arr[i]);
            heapify(i, 0);
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
        heapSort();
    }
};

int main() {
    HeapSort obj;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Enter array\n2. Heap Sort\n3. Display\n4. Quit\n";
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
