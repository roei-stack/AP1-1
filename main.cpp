#include "Reader.h"
#include "KnnClassifier.h"
#define K 11

/** @param dataset prints the data to the console */
void printData(const vector<Classifiable*>* dataset) {
    int i = 1;
    cout << "*********************************************" << endl << "Reading from classified..." << endl;
    for (Classifiable* c : *dataset) {
        cout << "Line #" << i << " Classification: " << c->getClassification() << endl;
        i++;
    }
    cout << i - 1 << " Lines read successfully!" << endl << "*********************************************" << endl;
}

/**
 * goes through all unclassified data and applies the classify function
 * @param classifiedData the classified data
 * @param unclassifiedData the unclassified data
 */
void classifyAll(vector<Classifiable*>* classifiedData, vector<Classifiable*>* unclassifiedData) {
    KnnClassifier classifier(K, classifiedData);
    for (Classifiable* c: *unclassifiedData) {
        c->setClassification(classifier.classify(*c));
    }
}

int main()
{
    string classifiedPath = "..\\classified.csv";
    string unclassifiedPath = "..\\unclassified.csv";
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
    //todo write the unclassified data to a new csv file
    //todo make sure the data is entered in the right order
    return 0;
}
