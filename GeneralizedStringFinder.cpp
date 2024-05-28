#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* args[]) {
    if (argc < 4) {
        cout << "Requires more arguments! Usage: " << args[0] <<" filenameToRead outputFileName minimumToFind {extraFindStep1, extraFindStep2...}";
        return 1;
    }

    string inputFilename = args[1];
    string outputFilename = args[2];

    ifstream input(inputFilename, ios::ate);
    
    if (!input.is_open()) {
        cout << "Unable to open file to read! Filename: " << inputFilename;
        return 2;
    }

    unsigned long long size = input.tellg();
    string inputString(size, '\0');
    input.seekg(0);
    input.read(&inputString[0], size);
    input.close();

    size_t lastFind = -1;
    int lastFindLength = 0;

    vector<vector<vector<unsigned long long>>> findings;

    vector<string> toFind;

    for (int i = 3; i < argc; i++) {
        toFind.push_back(args[i]);
    }

    string full = "";
    
    for (int i = 0; i < toFind.size(); i++) {
        full.append(toFind[i]);
    }

    for (int i = 0; i <= full.length(); i++) {
        vector<vector<unsigned long long>> tmp;
        findings.push_back(tmp);
    }

    do {
        lastFind = inputString.find(toFind[0], lastFind+1);

        if (lastFind == string::npos) {
            break;
        } else {
            lastFindLength = toFind[0].length();
        }

        for (int i = 1; i < toFind.size(); i++) {
            if (inputString.substr(lastFind + lastFindLength, 1) == toFind[i]) {
                lastFindLength++;
            } else {
                break;
            }
        }

        vector<unsigned long long> data;

        data.push_back(lastFind);
        data.push_back(lastFindLength);

        findings[lastFindLength].push_back(data);
    } while (lastFind + lastFindLength < inputString.length());

    ofstream output;
    output.open(outputFilename);

    while (!output.is_open()) {
        cout << "Error opening output file! Filename: " << outputFilename << endl;
        cout << "Please enter a different output filename: ";

        getline(cin, outputFilename);
        output.open(outputFilename);
    }

    for (int i = 1; i < findings.size(); i++) {
        output << "#" << full.substr(0, i) << ":\n";
        for (int j = 0; j < findings[i].size(); j++) {
            output << "\t" << findings[i][j][0] + 1 << "-" << findings[i][j][0] + findings[i][j][1] << endl;
        }
    }

    output.close();

    return 0;
}