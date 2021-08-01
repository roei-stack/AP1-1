#include <iostream>
#include <fstream>
using namespace std;
class Reader {
    private:
     ifstream file;
    public:
     // constructor
     explicit Reader(string filePath);
     // returns the current line and moves to the next line
     const string* readLine();
     // translates the line into an Iris type object
     void parseLine();
};