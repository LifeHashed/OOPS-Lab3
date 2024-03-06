#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex() : real(0.0), imaginary(0.0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}


    // Operator overloading for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }


    // Operator overloading for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }


    // Operator overloading for multiplication
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imaginary * other.imaginary),
                       (real * other.imaginary) + (imaginary * other.real));
    }


    // Operator overloading for division
    Complex operator/(const Complex& other) const {
        double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
        return Complex(((real * other.real) + (imaginary * other.imaginary)) / denominator,
                       ((imaginary * other.real) - (real * other.imaginary)) / denominator);
    }


    // Operator overloading for conjugate
    Complex operator!() const {
        return Complex(real, -imaginary);
    }


    // Operator overloading for comparison (==)
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }


    // Operator overloading for comparison (!=)
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Input-Output overloading
    friend std::istream& operator>>(std::istream& in, Complex& complex);
    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};


// Input overloading
std::istream& operator>>(std::istream& in, Complex& complex) {
    in >> complex.real >> complex.imaginary;
    return in;
}

// Output overloading
std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if(complex.imaginary>0){
        out << complex.real << " + " << complex.imaginary << "i";
    } else{
        out << complex.real << " - " << -complex.imaginary << "i";
    }
    return out;
}

int main() {
    Complex c1, c2;
    std::cout << "Enter two complex numbers (real and imaginary parts):" << std::endl;
    std::cin >> c1 >> c2;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;
    Complex conjugate = !c1;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;
    std::cout << "Conjugate of the first number: " << conjugate << std::endl;

    // Testing comparison
    if (c1 == c2) {
        std::cout << "The two complex numbers are equal." << std::endl;
    } else {
        std::cout << "The two complex numbers are not equal." << std::endl;
    }
    return 0;
}
