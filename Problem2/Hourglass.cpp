#include <iostream>
#include <iomanip>

using namespace std;

class NumberPyramid {
private:
    int n;

public:
    NumberPyramid(int size) : n(size) {}

    void display() {
        
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < i; j++) {
                cout << setw(2) << " ";
            }

            
            for (int j = i + 1; j <= n; j++) {
                cout << setw(2) << j;
            }

            
            for (int j = n - 1; j >= i + 1; j--) {
                cout << setw(2) << j;
            }

            
            cout << endl;
        }

        
        for (int i = 1; i < n; i++) {
            
            for (int j = 0; j < n - i - 1; j++) {
                cout << setw(2) << " ";
            }

            
            for (int j = n - i; j <= n; j++) {
                cout << setw(2) << j;
            }

            
            for (int j = n - 1; j >= n - i; j--) {
                cout << setw(2) << j;
            }

            
            cout << endl;
        }
    }
};

int main() {
    int size;

    
    cout << "Enter the value of 'n': ";
    cin >> size;

    NumberPyramid pyramid(size);
    pyramid.display();

    return 0;
}