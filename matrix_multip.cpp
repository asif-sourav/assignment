#include <iostream>
using namespace std;

int main() {
    int M = 2, P = 3, N = 3;
    int matrix_a[2][3] = {{1, -2, 3}, {0, 4, 5}};
    int matrix_b[3][3] = {{3, 0, -6}, {2, -3, 1}, {2, 5, 3}};
    int matrix_c[10][10];   // Result matrix

    // Initialize result matrix to 0
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            matrix_c[i][j] = 0;

    // Matrix multiplication
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < P; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    // Print result
    cout << "Resultant Matrix:\n";
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << matrix_c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
