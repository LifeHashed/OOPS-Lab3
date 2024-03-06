#include <iostream>
#include <set>

class Set {
private:
    std::set<int> elements;


public:
    // Default constructor
    Set() {}


    // Constructor with initial elements
    Set(const std::set<int>& initialElements) : elements(initialElements) {}


    // Copy constructor
    Set(const Set& other) : elements(other.elements) {}


    // Operator overloading for union (+)
    Set operator+(const Set& other) const {
        Set result(*this);
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }


    // Operator overloading for difference (-)
    Set operator-(const Set& other) const {
        Set result(*this);
        for (int element : other.elements) {
            result.elements.erase(element);
        }
        return result;
    }


    // Operator overloading for intersection (*)
    Set operator*(const Set& other) const {
        Set result;
        for (int element : elements) {
            if (other.elements.count(element) > 0) {
                result.elements.insert(element);
            }
        }
        return result;
    }

    // Operator overloading for subset (<)
    bool operator<(const Set& other) const {
        for (int element : elements) {
            if (other.elements.count(element) == 0) {
                return false;
            }
        }
        return true;
    }

    // Operator overloading for subset or equal (<=)
    bool operator<=(const Set& other) const {
        return (*this < other) || (*this == other);
    }


    // Operator overloading for superset (>)
    bool operator>(const Set& other) const {
        return other < *this;
    }


    // Operator overloading for superset or equal (>=)
    bool operator>=(const Set& other) const {
        return (*this > other) || (*this == other);
    }


    // Operator overloading for equality (==)
    bool operator==(const Set& other) const {
        return elements == other.elements;
    }


    // Operator overloading for inequality (!=)
    bool operator!=(const Set& other) const {
        return !(*this == other);
    }


    // Operator overloading for assignment (=)
    Set& operator=(const Set& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }


    // Input-Output overloading
    friend std::istream& operator>>(std::istream& in, Set& set);
    friend std::ostream& operator<<(std::ostream& out, const Set& set);
};


// Input overloading
std::istream& operator>>(std::istream& in, Set& set) {
    int size;
    std::cout << "Enter the size of the set: ";
    in >> size;


    set.elements.clear(); // Clear existing elements


    std::cout << "Enter the elements of the set:" << std::endl;
    for (int i = 0; i < size; ++i) {
        int element;
        in >> element;
        set.elements.insert(element);
    }


    return in;
}


// Output overloading
std::ostream& operator<<(std::ostream& out, const Set& set) {
    out << "{ ";
    for (int element : set.elements) {
        out << element << " ";
    }
    out << "}";
    return out;
}


int main() {
    Set set1, set2;
    std::cout << "Enter elements for the first set:" << std::endl;
    std::cin >> set1;


    std::cout << "Enter elements for the second set:" << std::endl;
    std::cin >> set2;


    Set unionSet = set1 + set2;
    Set differenceSet = set1 - set2;
    Set intersectionSet = set1 * set2;


    std::cout << "Union of sets: " << unionSet << std::endl;
    std::cout << "Difference of sets: " << differenceSet << std::endl;
    std::cout << "Intersection of sets: " << intersectionSet << std::endl;


    // Testing subset and superset
    if (set1 < set2) {
        std::cout << "Set 1 is a subset of Set 2." << std::endl;
    } else if (set1 > set2) {
        std::cout << "Set 1 is a superset of Set 2." << std::endl;
    } else {
        std::cout << "Set 1 is neither a subset nor a superset of Set 2." << std::endl;
    }


    // Testing equality
    if (set1 == set2) {
        std::cout << "The two sets are equal." << std::endl;
    } else {
        std::cout << "The two sets are not equal." << std::endl;
    }

    return 0;
}
