#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void indent(const string &InputFileName, const string &OutputFileName ){
    ifstream inputFile(InputFileName);
    if (!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
        exit(EXIT_FAILURE);
    }

    ofstream outputFile(OutputFileName);
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int tab=0;

    while(getline(inputFile,line)){
        for(char c:line){
            if(c=='{'){
                tab++;
            }
            else if(c=='}'){
                tab--;
            }
        }

         for (int i = 0; i < tab; i++) {
            outputFile << "    ";  
        }

        
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();


}

int main(){
    const string inputFileName="Readcpp.cpp";
    const string outputFileName="Outcpp.cpp";

    indent(inputFileName, outputFileName);

    cout << "Code has been indented and saved in \"" << outputFileName << "\"" << endl;

    return 0;
}