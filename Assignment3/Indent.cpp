#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void indent(const string &inputFileName, const string &outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        inputFile.close();
        exit(EXIT_FAILURE);
    }

    string line;
    int tab = 0;

    while (getline(inputFile, line)) {
        // Count opening and closing braces to determine the level of indentation
        for (char c : line) {
            if (c == '{') {
                tab++;
            } else if (c == '}') {
                tab--;
            }
        }

        // Append indentation spaces to the output file
        for (int i = 0; i < tab; i++) {
            outputFile << "    ";  // You can adjust the number of spaces for each level of indentation
        }

        // Append the current line to the output file
        outputFile << line << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();
}

int main() {
    const string inputFileName = "Readcpp.cpp";   
    const string outputFileName = "Outcpp.cpp"; 

    indent(inputFileName, outputFileName);

    cout << "Code has been indented and saved in \"" << outputFileName << "\"" << endl;

    return 0;
}
