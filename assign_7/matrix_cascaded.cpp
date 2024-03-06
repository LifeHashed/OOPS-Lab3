#include <iostream>
using namespace std;


class matrix {
private:
   int rows;
   int cols;
   int **data;


public:
   matrix(int r = 0, int c = 0) : rows(r), cols(c) {
       data = new int*[rows];
       for (int i = 0; i < rows; ++i) {
           data[i] = new int[cols];
           for (int j = 0; j < cols; ++j) {
               data[i][j] = 0;  // Initialize elements to 0
           }
       }
   }


   matrix(const matrix& other) : rows(other.rows), cols(other.cols) {
       data = new int*[rows];
       for (int i = 0; i < rows; ++i) {
           data[i] = new int[cols];
           for (int j = 0; j < cols; ++j) {
               data[i][j] = other.data[i][j];
           }
       }
   }


   ~matrix() {
       for (int i = 0; i < rows; ++i) {
           delete[] data[i];
       }
       delete[] data;
   }


   matrix& incrMat() {
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               ++data[i][j];
           }
       }
       return *this;
   }


   void display() const {
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               cout << data[i][j] << " ";
           }
           cout << endl;
       }
   }
};


int main(void) {
   matrix m1(2, 3);


   {
       matrix m2 = m1;
       m2.incrMat().incrMat().incrMat();
       m2.display();
   }
   cout<<endl;
   m1.display();


   return 0;
}
