#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
vector<vector<int>> scalarMultiplyMatrix(const vector<vector<int>>& A, int scalar) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] * scalar;
        }
    }
    return result;
}

// Function to create an identity matrix
vector<vector<int>> identityMatrix(int n) {
    vector<vector<int>> identity(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }
    return identity;
}

// Function to evaluate the polynomial f(X) = X^3 - 5X^2 + 6X + 7I
vector<vector<int>> evaluatePolynomial(const vector<vector<int>>& X) {
    int n = X.size();

    // Compute X^2
    vector<vector<int>> X2 = multiplyMatrices(X, X);

    // Compute X^3
    vector<vector<int>> X3 = multiplyMatrices(X2, X);

    // Compute -5X^2
    vector<vector<int>> minus5X2 = scalarMultiplyMatrix(X2, -5);

    // Compute 6X
    vector<vector<int>> sixX = scalarMultiplyMatrix(X, 6);

    // Compute 7I
    vector<vector<int>> sevenI = scalarMultiplyMatrix(identityMatrix(n), 7);

    // Evaluate f(X) = X^3 - 5X^2 + 6X + 7I
    vector<vector<int>> result = addMatrices(X3, minus5X2);
    result = addMatrices(result, sixX);
    result = addMatrices(result, sevenI);

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define a 3x3 matrix
    vector<vector<int>> X = {
        {2, 0, 1},
        {0, 1, 2},
        {1, 2, 0}
    };

    // Evaluate the polynomial f(X)
    vector<vector<int>> result = evaluatePolynomial(X);

    // Print the result
    cout << "The result of the polynomial f(X) = X^3 - 5X^2 + 6X + 7I is:" << endl;
    printMatrix(result);

    return 0;
}
