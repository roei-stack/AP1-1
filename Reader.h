#include <iostream>
#include <fstream>
#include <vector>
#include "Classifiable.h"
#include "Iris.h"

using namespace std;
class Reader {
private:
    ifstream file;
    void readLine(string& line);
    static void parseLine(const string& line, Classifiable* c);
    void close();

public:
    explicit Reader(const string& filePath);

    vector<Classifiable*>* buildDataset();
};