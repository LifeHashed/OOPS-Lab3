#include <iostream>

class Matrix {
protected:
    int arr[3][3];

public:
    void show() {
        std::cout << "Matrix Contents:" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class MatrixA : public Matrix {
public:
    void read() {
        std::cout << "Enter MatrixA elements:" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cin >> arr[i][j];
            }
        }
    }
};

class MatrixB : public MatrixA {
public:
    void read() {
        std::cout << "Enter MatrixB elements:" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cin >> arr[i][j];
            }
        }
    }
};

int main() {
    MatrixB matrixB;
    matrixB.read();
    matrixB.show();
}