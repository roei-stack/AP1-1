//
// Created by user on 7/31/2021.
//

#ifndef ASS1_KNNCLASSIFIER_H
#define ASS1_KNNCLASSIFIER_H

#include <Classifier.h>
#include <Classifiable.h>
#include <vector>

class KnnClassifier : public Classifier {
private:
    int k;
    vector<Classifiable> dataset;

public:
    KnnClassifier(int k, const vector<Classifiable>& dataset);

    string classify(Classifiable c) override;
};


#endif //ASS1_KNNCLASSIFIER_H
