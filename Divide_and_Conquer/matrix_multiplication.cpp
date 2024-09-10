#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Helper function to add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Helper function to subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's algorithm to multiply two matrices
Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Dividing matrix A and B into 4 submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating the 7 products using Strassen's formula
    Matrix P1 = strassen(add(A11, A22), add(B11, B22));       // P1 = (A11 + A22) * (B11 + B22)
    Matrix P2 = strassen(add(A21, A22), B11);                 // P2 = (A21 + A22) * B11
    Matrix P3 = strassen(A11, subtract(B12, B22));            // P3 = A11 * (B12 - B22)
    Matrix P4 = strassen(A22, subtract(B21, B11));            // P4 = A22 * (B21 - B11)
    Matrix P5 = strassen(add(A11, A12), B22);                 // P5 = (A11 + A12) * B22
    Matrix P6 = strassen(subtract(A21, A11), add(B11, B12));  // P6 = (A21 - A11) * (B11 + B12)
    Matrix P7 = strassen(subtract(A12, A22), add(B21, B22));  // P7 = (A12 - A22) * (B21 + B22)

    // Combining the 7 products to get the final submatrices of C
    Matrix C11 = add(subtract(add(P1, P4), P5), P7);  // C11 = P1 + P4 - P5 + P7
    Matrix C12 = add(P3, P5);                         // C12 = P3 + P5
    Matrix C21 = add(P2, P4);                         // C21 = P2 + P4
    Matrix C22 = add(subtract(add(P1, P3), P2), P6);  // C22 = P1 + P3 - P2 + P6

    // Combining C11, C12, C21, C22 into the result matrix C
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (must be a power of 2): ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];

    Matrix C = strassen(A, B);

    cout << "Resultant matrix after multiplication:" << endl;
    printMatrix(C);

    return 0;
}
