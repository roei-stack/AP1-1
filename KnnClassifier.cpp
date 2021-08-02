//
// Created by user on 7/31/2021.
//

#include "KnnClassifier.h"
#include <Classifiable.h>
#include <algorithm>

KnnClassifier::KnnClassifier(int k, const vector<Classifiable>* dataset) {
    this->k = k;
    this->dataset = dataset;
}

string KnnClassifier::classify(const Classifiable c) {
    // sorting the data set according to the distance from c
    class ClassifiablesComparatorByDistToClassifiable {
    private:
        const Classifiable& classifiable;
    public:
        explicit ClassifiablesComparatorByDistToClassifiable(const Classifiable& c) : classifiable(c) {}

        bool operator() (const Classifiable& c1,const Classifiable& c2) {
            return classifiable.getDistance(c1) < classifiable.getDistance(c2);
        }
    };
    ClassifiablesComparatorByDistToClassifiable cmp(c);
    nth_element(this->dataset->begin(), this->dataset->begin() + k, this->dataset->end(), cmp);
    // todo - in the nearest k, count # of shows of each classification.
    //todo - find the classification with the max # of shows.
    //todo - return it
    return "";
}




