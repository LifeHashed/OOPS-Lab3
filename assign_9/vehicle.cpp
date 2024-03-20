#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
	int numWheels;
	int speed;

public:
	Vehicle(int wheels, int spd) : numWheels(wheels), speed(spd) {}

	virtual void displayInfo() {
    	cout << "Number of Wheels: " << numWheels << endl;
    	cout << "Speed: " << speed << " mph" << endl;
	}

	void compareSpeed(Vehicle &other) {
    	if (speed > other.speed)
        	cout << "Vehicle 1 is faster." << endl;
    	else if (speed < other.speed)
        	cout << "vehicle 1 is slower." << endl;
    	else
        	cout << "Both vehicles have the same speed." << endl;
	}
};

class Car : public Vehicle {
private:
	int numPassengers;

public:
	Car(int wheels, int spd, int passengers) : Vehicle(wheels, spd), numPassengers(passengers) {}

	void displayInfo() override {
    	cout << "Car Information:" << endl;
    	Vehicle::displayInfo();
    	cout << "Number of Passengers: " << numPassengers << endl;
	}
};

class Truck : public Vehicle {
private:
	int loadLimit;

public:
	Truck(int wheels, int spd, int limit) : Vehicle(wheels, spd), loadLimit(limit) {}

	void displayInfo() override {
    	cout << "Truck Information:" << endl;
    	Vehicle::displayInfo();
    	cout << "Load Limit: " << loadLimit << " tons" << endl;
	}
};

int main() {
	Car car(4, 120, 5);
	Truck truck(6, 80, 10);

	car.displayInfo();
	cout << endl;
	truck.displayInfo();
	cout << endl;

	car.compareSpeed(truck);
}

// #include <iostream>

// class Vehicle {
// protected:
//     int numWheels;
//     int speed;

// public:
//     Vehicle(int wheels, int spd) : numWheels(wheels), speed(spd) {}

//     void displayInfo() {
//         std::cout << "Number of wheels: " << numWheels << std::endl;
//         std::cout << "Speed: " << speed << " km/h" << std::endl;
//     }
// };

// class Car : public Vehicle {
// private:
//     int numPassengers;

// public:
//     Car(int wheels, int spd, int passengers) : Vehicle(wheels, spd), numPassengers(passengers) {}

//     void displayInfo() {
//         Vehicle::displayInfo();
//         std::cout << "Number of passengers: " << numPassengers << std::endl;
//     }
// };

// class Truck : public Vehicle {
// private:
//     int loadLimit;

// public:
//     Truck(int wheels, int spd, int limit) : Vehicle(wheels, spd), loadLimit(limit) {}

//     void displayInfo() {
//         Vehicle::displayInfo();
//         std::cout << "Load limit: " << loadLimit << " tons" << std::endl;
//     }
// };

// int main() {
//     Car car(4, 120, 5);
//     Truck truck(6, 80, 10);

//     std::cout << "Car information:" << std::endl;
//     car.displayInfo();
//     std::cout << std::endl;

//     std::cout << "Truck information:" << std::endl;
//     truck.displayInfo();
//     std::cout << std::endl;

//     if (car.speed < truck.speed) {
//         std::cout << "Car is slower than the truck." << std::endl;
//     } else {
//         std::cout << "Car is faster than or equal to the truck." << std::endl;
//     }

//     return 0;
// }
