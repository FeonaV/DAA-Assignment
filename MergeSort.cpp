#include <iostream>
using namespace std;

const int MAX = 100;

class MergeSort {
    int arr[MAX];
    int n = 0;
    void mergeParts(int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        int L[MAX], R[MAX];
        for (int x = 0; x < n1; x++) L[x] = arr[l + x];
        for (int y = 0; y < n2; y++) R[y] = arr[m + 1 + y];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
    void mergeSort(int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            mergeParts(l, m, r);
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
        if (n > 0) mergeSort(0, n - 1);
    }
};

int main() {
    MergeSort obj;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Enter array\n2. Merge Sort\n3. Display\n4. Quit\n";
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
