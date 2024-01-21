#include <bits/stdc++.h>
#include <iomanip>

#define PI 3.14159265

int main() {
    double theta_initial, theta_final, step_count;
    char fill_char;

    // Get user input
    std::cout << "Enter initial theta (in degrees): ";
    std::cin >> theta_initial;
    std::cout << "Enter final theta (in degrees): ";
    std::cin >> theta_final;
    std::cout << "Enter step count: ";
    std::cin >> step_count;
    std::cout << "Enter character to fill the pattern: ";
    std::cin >> fill_char;

    // Calculate step size
    double step_size = (theta_final - theta_initial) / step_count;

    // Display damped oscillation
    for (double theta = theta_initial; theta <= theta_final; theta += step_size) {
        double radian = theta * PI / 180.0;
        double oscillation = exp(-0.05 * radian) * cos(radian);

        int fill_count = static_cast<int>(20 * (oscillation + 1));
        std::cout << std::setw(10) << theta << " : " << std::string(fill_count, fill_char) << std::endl;
    }

 return 0;
}