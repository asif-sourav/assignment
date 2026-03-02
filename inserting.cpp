#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position to insert: ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;

    // Shift elements to right
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;  // Insert value
    n++;  // Increase size

    cout << "Array after insertion:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
