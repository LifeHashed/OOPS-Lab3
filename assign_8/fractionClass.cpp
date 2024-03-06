#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(1);
        }
        normalize();
    }


    // Helper function to normalize the fraction
    void normalize() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int gcd = calculateGCD(std::abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }


    // Helper function to calculate the greatest common divisor (GCD)
    int calculateGCD(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }


    // Operator overloading for addition
    Fraction operator+(const Fraction& other) const {
        return Fraction((numerator * other.denominator) + (other.numerator * denominator),
                        denominator * other.denominator);
    }


    // Operator overloading for subtraction
    Fraction operator-(const Fraction& other) const {
        return Fraction((numerator * other.denominator) - (other.numerator * denominator),
                        denominator * other.denominator);
    }


    // Operator overloading for multiplication
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }


    // Operator overloading for division
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            exit(1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }


    // Operator overloading for unary normalization
    Fraction operator*() const {
        Fraction result = *this;
        result.normalize();
        return result;
    }


    // Operator overloading for comparison (==)
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }


    // Operator overloading for comparison (!=)
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }


    // Operator overloading for less than (<)
    bool operator<(const Fraction& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }


    // Operator overloading for greater than (>)
    bool operator>(const Fraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }


    // Operator overloading for assignment (=)
    Fraction& operator=(const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }


    // Input-Output overloading
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};


// Input overloading
std::istream& operator>>(std::istream& in, Fraction& fraction) {
    in >> fraction.numerator >> fraction.denominator;
    if (fraction.denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        exit(1);
    }
    fraction.normalize();
    return in;
}


// Output overloading
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator;
    if (fraction.denominator != 1) {
        out << "/" << fraction.denominator;
    }
    return out;
}


int main() {
    Fraction f1, f2;
    std::cout << "Enter two fractions (numerator and denominator):" << std::endl;
    std::cin >> f1 >> f2;


    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;
    Fraction normalizedF1 = *f1;
    Fraction normalizedF2 = *f2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;
    std::cout << "Normalized Fraction 1: " << normalizedF1 << std::endl;
    std::cout << "Normalized Fraction 2: " << normalizedF2 << std::endl;

    // Testing comparison
    if (f1 == f2) {
        std::cout << "The two fractions are equal." << std::endl;
    } else {
        std::cout << "The two fractions are not equal." << std::endl;
    }


    // Testing less than and greater than
    if (f1 < f2) {
        std::cout << "Fraction 1 is less than Fraction 2." << std::endl;
    } else if (f1 > f2) {
        std::cout << "Fraction 1 is greater than Fraction 2." << std::endl;
    } else {
        std::cout << "Fraction 1 is equal to Fraction 2." << std::endl;
    }

    return 0;
}
