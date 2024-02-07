#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
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
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isSymmetric() {
        if (rows == cols) {
            Matrix transpose(rows, cols);
            for (int i=0; i<rows; i++){
                for (int j=0; j<rows; j++) {
                    transpose.matrix[i][j] = matrix[j][i];
                }
            }
            int flag=1;
            for (int i=0; i<rows; i++){
                for (int j=0; j<rows; j++) {
                    if (transpose.matrix[i][j] != matrix[i][j]){
                        flag=0;
                        break;
                    }
                }
            }
            if (flag==1){
                cout << "YES symmetric" << endl;
            } else{
                cout << "NOT symmetric" << endl;
            }
        } else{
            cout << "Symmetricity is only for square matrices" << endl;
        }
    }

    int isIden_Matrix(const Matrix& other) const {
        int res=1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != other.matrix[i][j]){
                    res=0;
                    break;
                }
            }
        }
        return res;
    }

    Matrix addMatrix(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix multiplyMatrix(const Matrix& other) const {
        
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

    int determinant() const {
        if (rows == 1 && cols == 1) {
            return (matrix[0][0]);
        }
        if (rows == 2 && cols == 2) {
            return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        } else {
            cerr << "Determinant calculation is supported only for 2x2 matrices." << endl;
            return 0;
        }
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
    cout << "After addition:" << endl;
    sumMatrix.displayMatrix();
    Matrix productMatrix = matrix1.multiplyMatrix(matrix2);
    cout << "After addition:" << endl;
    productMatrix.displayMatrix();
    cout << "Determinant of the first matrix: " << matrix1.determinant() << endl;
    cout << "Determinant of the second  matrix: " << matrix2.determinant() << endl;
    cout << "Symmetricity of first matrix: " << endl;
    matrix1.isSymmetric();
    cout << "Symmetricity of second matrix: " << endl;
    matrix2.isSymmetric();
    int res=matrix1.isIden_Matrix(matrix2);
    if(res==0)
    cout << "Matrices are not identical" << endl;
    else
    cout << "Matrices are identical" << endl;
}