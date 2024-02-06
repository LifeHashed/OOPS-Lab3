#include <iostream>

class SparseMatrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    SparseMatrix(int n) : rows(n), cols(n) {
        // Allocate memory for the 2D array
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~SparseMatrix() {
        // Deallocate memory for the 2D array
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void tridiagonalRowMajor() {
        std::cout << "Tridiagonal Sparse Matrix (Row-Major):\n";
        // Initialize the matrix with tridiagonal values
        int c=1;
        if(rows<=6){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == j  ){//i == j - 1 || i == j + 1) {
                    matrix[i][j] = c++;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        }
        else{
           for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == j  ||  i== j - 1 || i == j + 1) {
                    matrix[i][j] = c++;
                } else {
                    matrix[i][j] = 0;
                }
            }
        } 
        }
        display();
    }

    void tridiagonalColumnMajor() {
        std::cout << "Tridiagonal Sparse Matrix (Column-Major):\n";
        // Initialize the matrix with tridiagonal values
        int c=1;
        if(rows<=6){
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (i == j ){//|| i == j - 1 || i == j + 1) {
                    matrix[i][j] = c++;;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        }
        else{
            for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (i == j || i == j - 1 || i == j + 1) {
                    matrix[i][j] = c++;;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        }
        display();
    }

    void asymmetricSparseMatrix() {
        std::cout << "Asymmetric Sparse Matrix:\n";
        // Initialize the matrix with asymmetric values
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = (i % 2 == 0) ? 1 : 0;
            }
        }
        display();
    }

    void display() {
        // Display the matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the matrix (n x n): ";
    std::cin >> n;

    SparseMatrix tridiagonalMatrix(n);

    // Tridiagonal Sparse Matrix using row-major operation
    tridiagonalMatrix.tridiagonalRowMajor();

    // Tridiagonal Sparse Matrix using column-major operation
    tridiagonalMatrix.tridiagonalColumnMajor();

    // Asymmetric Sparse Matrix
    tridiagonalMatrix.asymmetricSparseMatrix();

    return 0;
}
