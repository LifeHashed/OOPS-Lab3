#include <iostream>
using namespace std;

class Matrix{
    private:
    int rows;
    int cols;
    int** matrix;

    public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocateSpace();
    }

    ~Matrix() {
        deallocateSpace();
    }

    void allocateSpace() {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    void deallocateSpace() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

     void readMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }


    Matrix addMatrix(Matrix& other){
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix multiplyMatrix(Matrix& other){
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    int determinant(){
        // Assuming it's a 2x2 matrix for simplicity
        if (rows == 2 && cols == 2) {
            return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        } else {
            cerr << "Determinant calculation is supported only for 2x2 matrices." <<endl;
            return 0;
        }

    
            
    /*
    if (rows == 0 ||cols == 0|| rows!=cols) {
        cerr << "Invalid matrix size." << endl;
        return 0.0;
    }

    if (rows == 1) {
        return matrix[0][0];
    }

    double det = 0.0;
    for (int i = 0; i < rows; i++) {
        Matrix submatrix(rows - 1, (rows - 1));
        for (int j = 1; j < rows; j++) {
            for (int k = 0, l = 0; k < rows; k++) {
                if (k != i) {
                    submatrix.matrix[j - 1][l++] = matrix[j][k];
                }
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix);
    }

    return det;
    */
}

        

    
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows for the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns for the matrix: ";
    cin >> cols;

    Matrix matrix1(rows, cols);
    matrix1.readMatrix();
    matrix1.displayMatrix();

    Matrix matrix2(rows, cols);
    matrix2.readMatrix();
    matrix2.displayMatrix();

    Matrix sumMatrix = matrix1.addMatrix(matrix2);
    sumMatrix.displayMatrix();

    Matrix productMatrix = matrix1.multiplyMatrix(matrix2);
    productMatrix.displayMatrix();

    cout << "Determinant of the first matrix: " << matrix1.determinant() << endl;

    return 0;
}











