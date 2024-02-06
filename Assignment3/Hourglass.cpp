#include <iostream>
#include <iomanip>

using namespace std;

class NumberPyramid {
private:
    int n;

public:
    NumberPyramid(int size) : n(size) {}

    void display() {
        // Display the number pyramid
        for (int i = 0; i < n; i++) {
            // Print leading spaces
            for (int j = 0; j < i; j++) {
                cout << setw(2) << " ";
            }

            // Print increasing numbers
            for (int j = i + 1; j <= n; j++) {
                cout << setw(2) << j;
            }

            // Print decreasing numbers
            for (int j = n - 1; j >= i + 1; j--) {
                cout << setw(2) << j;
            }

            // Move to the next line
            cout << endl;
        }

        // Display the bottom part of the hourglass
        for (int i = 1; i < n; i++) {
            // Print leading spaces
            for (int j = 0; j < n - i - 1; j++) {
                cout << setw(2) << " ";
            }

            // Print increasing numbers
            for (int j = n - i; j <= n; j++) {
                cout << setw(2) << j;
            }

            // Print decreasing numbers
            for (int j = n - 1; j >= n - i; j--) {
                cout << setw(2) << j;
            }

            // Move to the next line
            cout << endl;
        }
    }
};

int main() {
    int size;

    // Accept the value of 'n'
    cout << "Enter the value of 'n': ";
    cin >> size;

    NumberPyramid pyramid(size);
    pyramid.display();

    return 0;
}