//
// Created by user on 7/31/2021.
//

#include "KnnClassifier.h"
#include <Classifiable.h>
#include <algorithm>

KnnClassifier::KnnClassifier(int k, const vector<Classifiable> &dataset) {
    this->k = k;
    this->dataset = dataset;
}

string KnnClassifier::classify(const Classifiable c) {
    // sorting the data set according to the distance from c
    class Comparator {
    private:
        const Classifiable& classifiable;
    public:
        explicit Comparator(const Classifiable& c) : classifiable(c) {}

        bool operator() (const Classifiable& c1,const Classifiable& c2) {
            return classifiable.getDistance(c1) < classifiable.getDistance(c2);
        }
    };
    Comparator cmp(c);
    sort(this->dataset.begin(), this->dataset.end(), cmp);
    // todo - in the nearest k, count # of shows of each classification.
    //todo - find the classification with the max # of shows.
    //todo - return it
    return "";
}




