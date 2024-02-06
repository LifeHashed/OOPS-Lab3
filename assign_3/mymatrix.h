#ifndef MY_MATRIX_H
#define MY_MATRIX_H


class Matrix {
private:
    int **data;
    int size;


public:
    // Constructor to initialize the matrix with a given size
    Matrix(int size);


    // Destructor to free the dynamically allocated memory
    ~Matrix();


    // Function to set values in the matrix
    void setValues();


    // Function to display the matrix
    void display();


    // Function to perform matrix multiplication
    Matrix multiply(const Matrix &other) const;


    // Function to calculate the determinant of the matrix
    int determinant() const;


    // Function to get a column from the matrix
    const int* getColumn(int columnIndex) const;


    // Function to create a submatrix by excluding a specified row and column
    Matrix subMatrix(int excludingRow, int excludingCol) const;


private:
    // Helper function for matrix multiplication
    static int dotProduct(const int *rowA, const int *columnB, int size);
};


#endif  // MY_MATRIX_H

