#include <iostream>
#include <iomanip>

using namespace std;

class ButterflyPattern {
public:
    
    static void draw(int N) {
        int space = 2 * N - 1;
        int star = 0;

        for (int j = 1; j <= 2 * N - 1; j++) {
            if (j <= N) {
                space = space - 2;
                star++;
            } else {
                space = space + 2;
                star--;
            }

            

            for (int m = 1; m <= star; m++) {
                cout << "*";
            }

            for (int n = 1; n <= space; n++) {
                cout << " ";
            }

            for (int p = 1; p <= star; p++) {
                if (p != N) {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int N;

    
    cout << "Enter value of N: ";
    cin >> N;

    
    ButterflyPattern::draw(N);

    return 0;
}
