#include <iostream>
using namespace std;

class SparseMatrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    SparseMatrix(int n) : rows(n), cols(n) {
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~SparseMatrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void tridiagonalRowMajor() {
        cout << "Tridiagonal Sparse Matrix (Row-Major):\n";
        int c=1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == j || i == j - 1 || i == j + 1) {
                    matrix[i][j] = c;
                    c++;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        display();
    }

    void tridiagonalColumnMajor() {
        cout << "Tridiagonal Sparse Matrix (Column-Major):\n";
        int c=1;
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (i == j || i == j - 1 || i == j + 1) {
                    matrix[i][j] = c;
                    c++;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        display();
    }

    void asymmetricSparseMatrix() {
        cout << "Asymmetric Sparse Matrix:\n";
        int c=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (c>rows*cols/2){
                    matrix[i][j] = 0;
                }else{
                    matrix[i][j] = (i % 2 == 0) ? c : 0;
                    c++;
                }
            }
        }
        display();
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    SparseMatrix tridiagonalMatrix(n);
    tridiagonalMatrix.tridiagonalRowMajor();
    tridiagonalMatrix.tridiagonalColumnMajor();
    tridiagonalMatrix.asymmetricSparseMatrix();
}
