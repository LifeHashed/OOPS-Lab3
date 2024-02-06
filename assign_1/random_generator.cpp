#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

unsigned long long myrand() {
    static unsigned long long X = time(nullptr);
    unsigned long long a = 6364136223846793005ULL;
    unsigned long long m = 0x100000000ULL;
    X = (X * a) % m;
    return X;
}

int main() {
    const int N = 10000;
    const int range_min = 1;
    const int range_max = 50;
    const int intervals = 50;

    int myrand_counts[intervals] = {0};
    int rand_counts[intervals] = {0};

    // Generating random numbers using myrand() and rand()
    for (int i = 0; i < N; ++i) {
        int myrand_num = (myrand() % range_max) + range_min;
        int rand_num = (rand() % range_max) + range_min;
        myrand_counts[myrand_num - 1]++;
        rand_counts[rand_num - 1]++;
    }

    // Chi-square test calculation
    double myrand_chi_square = 0.0, rand_chi_square = 0.0;
    double expected_frequency = static_cast<double>(N) / intervals;

    for (int i = 0; i < intervals; ++i) {
        myrand_chi_square += pow(static_cast<double>(myrand_counts[i]) - expected_frequency, 2) / expected_frequency;
        rand_chi_square += pow(static_cast<double>(rand_counts[i]) - expected_frequency, 2) / expected_frequency;
    }

    std::cout << "Chi-square value for myrand(): " << myrand_chi_square << std::endl;
    std::cout << "Chi-square value for rand(): " << rand_chi_square << std::endl;

    // Commenting on acceptability
    if (myrand_chi_square <= 67.5 && rand_chi_square <= 67.5) {
        std::cout << "Both random series pass the Chi-square test (acceptable)." << std::endl;
    } else {
        std::cout << "At least one random series fails the Chi-square test (not acceptable)." << std::endl;
    }

    return 0;
}

