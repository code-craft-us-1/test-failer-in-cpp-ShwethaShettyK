#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using  std::stringstream, std::ios_base, std::string, std::cout, std::vector;

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int majorColorsCount = sizeof(majorColor) / sizeof(majorColor[0]);
int minorColorsCount = sizeof(minorColor) / sizeof(minorColor[0]);

stringstream printColorMap() {
    stringstream message("\n", ios_base::app | ios_base::out);
    int i = 0, j = 0, colorcode = 1;
    for (i = 0; i < majorColorsCount; i++) {
        for (j = 0; j < minorColorsCount; j++) {
            colorcode = (i*minorColorsCount+j)+1;
            message << colorcode << " | " <<majorColor[i]<< " | " <<minorColor[j]<< "\n";
        }
    }
    cout << message.str();
    return message;
}

void testprintColorMap() {
    std::string outtext;
    stringstream result(printColorMap().str());
    string line;
    vector<string> colormapList;
    // Loop until the end of the string
    while (getline(result, line)) {
        if (!line.empty()) {
            colormapList.push_back(line);
        }
    }
    for (int i = 0; i < majorColorsCount; i++) {
        for (int j = 0; j < minorColorsCount; j++) {
            int code = (i * minorColorsCount + j);
            string stringLine = colormapList.at(code);
            assert(stringLine.find(std::to_string(code + 1)) != string::npos);
            assert(stringLine.find(majorColor[i]) != string::npos);
            assert(stringLine.find(minorColor[j]) != string::npos);
        }
    }
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testprintColorMap();
    return 0;
}

