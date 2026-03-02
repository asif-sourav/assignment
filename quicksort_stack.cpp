#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int n) {
    int stack[100];
    int top = -1;

    // Push initial low and high
    stack[++top] = 0;
    stack[++top] = n - 1;

    while(top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        int pi = partition(arr, low, high);

        // If left subarray exists, push it
        if(pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // If right subarray exists, push it
        if(pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, n);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
