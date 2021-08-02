//
// Created by user on 7/31/2021.
//

#ifndef ASS1_KNNCLASSIFIER_H
#define ASS1_KNNCLASSIFIER_H

#include "Classifier.h"
#include "Classifiable.h"
#include <vector>


class KnnClassifier : public Classifier {
private:
    int k;
    const vector<Classifiable*>* dataset;

public:
    /**
     * constructor.
     * @param k the k of knn
     * @param dataset the dataset. *this classifier doesn't delete it when deleted itself*.
     */
    KnnClassifier(int k, const vector<Classifiable*>* dataset);

    /**
     * returns the classification of c
     * @param c an appropriate Classifiable such that
     *     c knows how to calculate the distance from the Classifiables in this Classifier's dataset.
     *     probably, c will have to be from the same type as them.
     *     **if other's type won't be appropriate, an exception may be thrown.**
     * @return string
     */
    string classify(const Classifiable& c) override;
};


#endif //ASS1_KNNCLASSIFIER_H
