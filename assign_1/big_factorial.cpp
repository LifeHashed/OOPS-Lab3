#include <iostream>
#include <string>

using namespace std;

string multiplyStrings(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    string result(len1 + len2, '0');

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j] = result[i + j] + sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
    }

    size_t start = result.find_first_not_of('0');
    if (start != string::npos) {
        return result.substr(start);
    }

    return "0";
}

string factorial(int n) {
    if (n == 0 || n == 1) {
        return "1";
    }

    string result = "1";
    for (int i = 2; i <= n; i++) {
        result = multiplyStrings(result, to_string(i));
    }

    return result;
}

int main() {
    int limit = 1000;
    string fact = factorial(limit);
    cout << "Factorial of " << limit << " is:\n" << fact << endl;

    return 0;
}

