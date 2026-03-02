#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key, pos = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    // Linear search
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            pos = i; // store index
            break;   // stop after first occurrence
        }
    }

    if(pos != -1)
        cout << "Element found at position: " << pos + 1 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
