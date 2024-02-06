#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class DampedOscillationPlot {
private:
    int initialTheta;
    int finalTheta;
    int stepCount;
    char fillChar;

public:
    // Constructor to initialize member variables
    DampedOscillationPlot(int initialTheta, int finalTheta, int stepCount, char fillChar)
        : initialTheta(initialTheta), finalTheta(finalTheta), stepCount(stepCount), fillChar(fillChar) {}

    // Member function to display the damped oscillation plot
    void display() {
        // Open a file for writing
        ofstream outFile("Damped_Oscillation_Plot.txt");

        if (!outFile.is_open()) {
            cerr << "Error opening the file for writing." << endl;
            exit(EXIT_FAILURE);
        }

        // Convert degrees to radians
        double initialThetaRad = initialTheta * M_PI / 180.0;
        double finalThetaRad = finalTheta * M_PI / 180.0;

        // Calculate the step size
        double stepSize = (finalThetaRad - initialThetaRad) / stepCount;

        // Display the plot header
        cout << "Theta (degrees)  |  Damped Oscillation" << endl;
        cout << "-----------------+---------------------" << endl;

        // Write the same header to the file
        outFile << "Theta (degrees)  |  Damped Oscillation" << endl;
        outFile << "-----------------+---------------------" << endl;

        // Loop through the theta values and calculate the damped oscillation
        for (double thetaRad = initialThetaRad; thetaRad <= finalThetaRad; thetaRad += stepSize) {
            double dampedOscillation = exp(-thetaRad) * cos(thetaRad);

            // Display the values with formatting
            cout << setw(16) << fixed << setprecision(2) << thetaRad * 180.0 / M_PI
                 << "  |  " << setw(18) << dampedOscillation << endl;

            // Write the same values to the file
            outFile << setw(16) << fixed << setprecision(2) << thetaRad * 180.0 / M_PI
                     << "  |  " << setw(18) << dampedOscillation << endl;
        }

        // Close the file
        outFile.close();
    }
};

int main() {
    int initialTheta, finalTheta, stepCount;
    char fillChar;

    // Accept input from the user
    cout << "Enter the initial theta (degrees): ";
    cin >> initialTheta;

    cout << "Enter the final theta (degrees): ";
    cin >> finalTheta;

    cout << "Enter the step count: ";
    cin >> stepCount;

    cout << "Enter the character to fill up the pattern: ";
    cin >> fillChar;

    // Create an object of the DampedOscillationPlot class
    DampedOscillationPlot plot(initialTheta, finalTheta, stepCount, fillChar);

    // Display the damped oscillation plot using the object
    plot.display();

    cout << "Damped oscillation plot has been generated and saved to 'damped_oscillation_plot.txt'" << endl;

    return 0;
}
