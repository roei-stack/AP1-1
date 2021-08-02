#include "Reader.h"
#include <sstream>

/**
 * @param filePath the path to the input file
 */
Reader::Reader(const string& filePath) {
    this->file.open(filePath);
    // taking care of bad inputs
    if (!this->file.is_open()) {
        throw invalid_argument("Failed to initialize file reader at path " + filePath);
    }
}

/**
 * builds the database from the csv file
 * @return a vector-list of pointers to heap-allocated Classifiable objects
 */
vector<Classifiable*> Reader::buildDataset() {
    int i = 1;
    vector<Classifiable*> data;
    string line;
    while (!this->file.eof()) {
        if (i == 105) {
            cout << "hi" << endl;
        }
        line = this->readLine();
        Iris c(0, 0, 0, 0, "");
        parseLine(line, &c);
        data.push_back(&c);
        cout << "line #" << i << ": " << line << endl;
        i++;
    }
    // Requests the container to reduce its capacity to fit its size, so no memory is wasted
    data.shrink_to_fit();
    // closing the file as we no longer need it
    this->close();
    return data;
}

/**
 * @return a new line from the file and moves to the next line
 */
string Reader::readLine() {
    string line;
    getline(this->file, line);
    return line;
}

/**
 * translates a string line into an object
 * @param line the given line
 * @return a pointer to classified object
 * remember to free the database
 */
void Reader::parseLine(const string& line, Classifiable* c) {
    double petalLength, sepalWidth, sepalLength, width;
    string type;
    //"petal length,sepal width, sepal length, width
    // array of 4 arguments = {
    stringstream values[5];
    stringstream check(line);
    string current;
    int i = 0;
    char delim = ',';
    while(getline(check, current, delim)) {
        values[i] << current;
        i++;
    }
    // assigning values
    values[0] >> petalLength;
    values[1] >> sepalWidth;
    values[2] >> sepalLength;
    values[3] >> width;
    values[4] >> type;
    // setting the object
    c->setValues(width, sepalLength, sepalWidth, petalLength, type);
}

/**
 * closes the file
 */
void Reader::close() {
    this->file.close();
}
