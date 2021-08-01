#include "Reader.h"

// constructor
explicit Reader::Reader(const string filePath) {
    this->file.open(filePath);
    // taking care of bad inputs
    if (!this->file.is_open()) {
        cout << "Failed opening the file!" << endl;
        exit(1);
    }
}

// returns a line from the file and moves to the next line
// returns nullptr when reaching end of file
const string* Reader::readLine() {
    string line;
    string* pline = &line;
    // checking if we can still read another line
    if (!this->file.eof()) {
        this->file >> line;
    }
    return pline;
}

// translates the line to an object
void Reader::parseLine() {
    const string* line = this->readLine();
    if (line == nullptr) {
        cout << "Reached end of file" << endl;
        return;
    }
    char delim = ',';
    int width;
    int sepalWidth;
    int sepalLenght;
    int petalLenght;
    
}
