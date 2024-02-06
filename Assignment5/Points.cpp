#include <iostream>
#include <cmath>

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class PointManager {
private:
    Point** points;  // Array of pointers to Point objects
    int size;

public:
    PointManager(int size) : size(size) {
        // Allocate memory for an array of pointers to Point objects
        points = new Point*[size];

        // Initialize each pointer with a new Point object
        for (int i = 0; i < size; ++i) {
            points[i] = new Point(0, 0);
        }
    }

    ~PointManager() {
        // Deallocate memory for each Point object
        for (int i = 0; i < size; ++i) {
            delete points[i];
        }

        // Deallocate memory for the array of pointers
        delete[] points;
    }

    void inputPoints() {
        std::cout << "Enter coordinates for 10 points:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "Point " << i + 1 << " (x y): ";
            std::cin >> points[i]->x >> points[i]->y;
        }
    }

    Point findClosestToOrigin() {
        Point closestPoint = *points[0];
        double minDistance = std::sqrt(points[0]->x * points[0]->x + points[0]->y * points[0]->y);

        for (int i = 1; i < size; ++i) {
            double distance = std::sqrt(points[i]->x * points[i]->x + points[i]->y * points[i]->y);
            if (distance < minDistance) {
                minDistance = distance;
                closestPoint = *points[i];
            }
        }

        return closestPoint;
    }

    void displayPoints() {
        std::cout << "\nCoordinates of the 10 points:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "Point " << i + 1 << ": (" << points[i]->x << ", " << points[i]->y << ")\n";
        }
    }

    void displayPlot() {
    std::cout << "\nPlot of the " << size << " points:\n";
    const int gridSize = 20;

    for (int y = gridSize; y >= -gridSize; --y) {
        for (int x = -gridSize; x <= gridSize; ++x) {
            bool pointExists = false;
            for (int i = 0; i < size; ++i) {
                if (points[i]->x == x && points[i]->y == y) {
                    std::cout << "* ";
                    pointExists = true;
                    break;
                }
            }
            if (!pointExists) {
                if (x == 0 && y == 0) {
                    std::cout << "O ";
                } else {
                    std::cout << ". ";
                }
            }
        }
        std::cout << std::endl;
    }
}
};



int main() {
    const int numPoints = 10;

    PointManager pointManager(numPoints);

    pointManager.inputPoints();

    Point closestPoint = pointManager.findClosestToOrigin();

    pointManager.displayPoints();

    std::cout << "\nThe point closest to the origin is: (" << closestPoint.x << ", " << closestPoint.y << ")\n";

    pointManager.displayPlot();

    return 0;
}
