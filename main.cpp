#include "Reader.h"
#include "KnnClassifier.h"

using namespace std;

void printData(const vector<Classifiable*>* dataset) {
    int i = 1;
    cout << "*********************************************" << endl << "Reading from classified..." << endl;
    for (Classifiable* c : *dataset) {
        cout << "Line #" << i << " Classification: " << c->getClassification() << endl;
        i++;
    }
    cout << i - 1 << " Lines read successfully!" << endl << "*********************************************" << endl;
}

void classifyAll(vector<Classifiable*>* classifiedData, vector<Classifiable*>* unclassifiedData) {
    KnnClassifier classifier(12, classifiedData);
    for (Classifiable* c: *unclassifiedData) {
        c->setClassification(classifier.classify(*c));
    }
}

int main()
{
    string classifiedPath = R"(C:\Users\User\Desktop\CPP\classified.csv)";
    string unclassifiedPath = R"(C:\Users\User\Desktop\CPP\unclassified.csv)";
    //// initializing the reader for classified and unclassified
    Reader reader(classifiedPath);
    Reader otherReader(unclassifiedPath);
    //// loading the datasets
    vector<Classifiable*>* classifiedData = reader.buildDataset();
    vector<Classifiable*>* unclassifiedData = otherReader.buildDataset();
    // todo delete these 2 lines after finishing
    printData(classifiedData);
    printData(unclassifiedData);
    // applying classifier
    classifyAll(classifiedData, unclassifiedData);

    cout << "lol";
    return 0;
}