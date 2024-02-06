#include<iostream>
#include<vector>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> matrix;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocate_space();
    }

    void allocate_space() {
        matrix.resize(rows, std::vector<int>(cols, 0));
    }

    void read_matrix() {
        std::cout << "Enter matrix elements row-wise:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
                std::cin >> matrix[i][j];
            }
        }
    }

    void display_matrix() {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add_matrix(const Matrix& other) {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    Matrix mult_matrix(const Matrix& other) {
        if (cols != other.rows) {
            std::cout << "Matrix multiplication not possible due to incompatible dimensions." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return result;
    }

    int det_matrix() {
        if (rows != cols) {
            std::cout << "Determinant calculation is only possible for square matrices." << std::endl;
            return 0;
        }

        int det = 1;
        std::vector<std::vector<int>> temp(matrix);

        for (int i = 0; i < rows; ++i) {
            // Finding pivot element
            int pivot = i;
            while (pivot < rows && temp[pivot][i] == 0) {
                ++pivot;
            }

            if (pivot == rows) {
                // No pivot element found, determinant is 0
                det = 0;
                break;
            }

            if (pivot != i) {
                // Swap rows if pivot element is not in the current row
                det *= -1; // Changing the sign when swapping rows
                std::swap(temp[i], temp[pivot]);
            }

            det *= temp[i][i];

            // Eliminate other elements in the current column
            for (int j = i + 1; j < rows; ++j) {
                int factor = temp[j][i] / temp[i][i];
                for (int k = i; k < cols; ++k) {
                    temp[j][k] -= factor * temp[i][k];
                }
            }
        }

        return det;
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns for the matrix: ";
    std::cin >> rows >> cols;

    Matrix matrix1(rows, cols);
    matrix1.read_matrix();

    std::cout << "\nMatrix 1:" << std::endl;
    matrix1.display_matrix();

    int det = matrix1.det_matrix();
    std::cout << "\nDeterminant of Matrix 1: " << det << std::endl;

    return 0;
}
