#include "mymatrix.h"
#include <iostream>


// Constructor
Matrix::Matrix(int size) : size(size) {
    // Allocate memory for the matrix
    data = new int *[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
    }
}


// Destructor
Matrix::~Matrix() {
    // Free the dynamically allocated memory
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}


//Get Column Method
const int* Matrix::getColumn(int columnIndex) const {
    int *column = new int[size];
    for (int i = 0; i < size; ++i) {
        column[i] = data[i][columnIndex];
    }
    return column;
}


// Function to set values in the matrix
void Matrix::setValues() {
    std::cout << "Enter matrix values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "Enter value for row " << i + 1 << " and column " << j + 1 << ": ";
            std::cin >> data[i][j];
        }
    }
}


// Function to display the matrix
void Matrix::display() {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// Function to perform matrix multiplication
Matrix Matrix::multiply(const Matrix &other) const {
    Matrix result(size);


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = dotProduct(data[i], other.getColumn(j), size);
        }
    }


    return result;
}


int Matrix::determinant() const {
    if (size == 1) {
        return data[0][0];
    }


    if (size == 2) {
        return (data[0][0] * data[1][1] - data[0][1] * data[1][0]);
    }


    int det = 0;


    for (int i = 0; i < size; ++i) {
        // Calculate the cofactor for the current element
        int sign = (i % 2 == 0) ? 1 : -1;
        int cofactor = sign * data[0][i] * Matrix(size - 1).subMatrix(0, i).determinant();


        // Accumulate the cofactor to the determinant
        det += cofactor;
    }


    return det;
}


// Function to create a submatrix by excluding a specified row and column
Matrix Matrix::subMatrix(int excludingRow, int excludingCol) const {
    Matrix subMat(size - 1);


    for (int i = 1, row = 0; i < size; ++i, ++row) {
        for (int j = 0, col = 0; j < size; ++j) {
            if (j != excludingCol) {
                subMat.data[row][col++] = data[i][j];
            }
        }
    }


    return subMat;
}


// Helper function for dot product
int Matrix::dotProduct(const int *rowA, const int *columnB, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += rowA[i] * columnB[i];
    }
    return result;
}


#include "mymatrix.h"


int main() {
    int n;


    // Get the size of the matrix from the user
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;


    // Create matrices
    Matrix matrixA(n);
    Matrix matrixB(n);


    // Set values for matrices
    std::cout << "Matrix A:" << std::endl;
    matrixA.setValues();


    std::cout << "Matrix B:" << std::endl;
    matrixB.setValues();


    // Display matrices
    std::cout << "\nMatrices:" << std::endl;
    matrixA.display();
    std::cout << std::endl;
    matrixB.display();


    // Perform matrix multiplication
    Matrix resultMatrix = matrixA.multiply(matrixB);


    // Display the result of matrix multiplication
    std::cout << "\nResult of Matrix Multiplication:" << std::endl;
    resultMatrix.display();


    // Calculate and display the determinant of matrixA
    int detA = matrixA.determinant();
    std::cout << "\nDeterminant of Matrix A: " << detA << std::endl;


    return 0;
}
