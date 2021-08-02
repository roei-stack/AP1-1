#include "Reader.h"
#include "KnnClassifier.h"

using namespace std;

int main()
{
    string classifiedPath = R"(C:\Users\User\Desktop\CPP\classified.csv)";
    string unclassifiedPath = R"(C:\Users\User\Desktop\CPP\unclassified.csv)";

    //// initializing the reader for classified
    Reader* reader = new Reader(classifiedPath);
    //// loading the dataset
    vector<Classifiable*>* dataset = reader->buildDataset();
    delete reader;
    reader = nullptr;

    //// creating the classifier
    KnnClassifier* classifier = new KnnClassifier(7, dataset);

    //// initializing  the reader for unclassifieds
    reader = new Reader(unclassifiedPath);
    //// loading the unclassifieds
    ////....
    delete reader;
    reader = nullptr;

    /**
     * todo:
     * for every classifiable in unclassified:
     *  -apply classify
     */

    delete classifier;
    delete dataset;

    return 0;
}