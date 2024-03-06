#include <iostream>
using namespace std;

class B;


class A {
private:
   int numA;


public:
   A() : numA(0) {}
   friend void displayNum(A, B);
   void setNumA(int value) {
       numA = value;
   }
};


class B {
private:
   int numB;


public:
   B() : numB(0) {}
   friend void displayNum(A, B);
   void setNumB(int value) {
       numB = value;
   }
};


void displayNum(A objA, B objB) {
   cout << "Displaying numbers from class A: " << objA.numA << endl;
   cout << "Displaying numbers from class B: " << objB.numB << endl;
}

int main() {
   A objA;
   B objB;
   objA.setNumA(5);
   objB.setNumB(10);
   displayNum(objA, objB);
}
