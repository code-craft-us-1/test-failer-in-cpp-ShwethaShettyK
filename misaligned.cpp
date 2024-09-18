#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
stringstream printColorMap() {
    stringstream message("\n",ios_base::app | ios_base::out);
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    cout << message.str();
    return message;
}

int main() {
    std::string outtext;
    stringstream result (printColorMap().str());
    string line;
    vector<string> stringList;
    // Loop until the end of the string
    while (getline(result, line)) {
        if (!line.empty()) {
            stringList.push_back(line);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int code = (i * 5+ j);
            string stringLine = stringList.at(code );
            assert(stringLine.find(std::to_string(code+1)) != string::npos);
            assert(stringLine.find(majorColor[i]) != string::npos);
            assert(stringLine.find(minorColor[j]) != string::npos);

        }
    }
    std::cout << "All is well (maybe!)\n";
    return 0;
}
