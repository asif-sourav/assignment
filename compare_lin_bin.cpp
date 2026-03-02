#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n = 100000;
    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int key = n; 
    clock_t start, end;

    start = clock();

    int pos1 = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            pos1 = i;
            break;
        }
    }

    end = clock();
    double linearTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();

    int low = 0, high = n - 1, pos2 = -1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            pos2 = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    end = clock();
    double binaryTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Linear Search Time: " << linearTime << " seconds" << endl;
    cout << "Binary Search Time: " << binaryTime << " seconds" << endl;

    return 0;
}
