#include "Reader.h"

using namespace std;

int main()
{
    string classifiedPath = R"(C:\Users\User\Desktop\CPP\classified.csv)";
    string unclassifiedPath = R"(C:\Users\User\Desktop\CPP\unclassified.csv)";
    // initializing the reader for classified
    Reader reader(classifiedPath);
    // loading the classifier and the database
    //KnnClassifier classifier(10, reader.buildDataset());
    /**
     * //todo:
     * for every classifiable in unclassified:
     *  -apply classified
     */
    return 0;
}