//
// Created by user on 7/31/2021.
//

#ifndef ASS1_CLASSIFIER_H
#define ASS1_CLASSIFIER_H

#include <string>
#include <Classifiable.h>

using namespace std;

/**
 * interface of a classifier.
 */
class Classifier {
public:
    /**
     * returns the classification of c.
     * @param c an appropriate Classifiable to classify - such that
     *     it knows how to calculate the distance from the items in this classifier's dataset.
     *     probably, other will have to be from the same type as them.
     *     if other's type won't be appropriate, an exception may be thrown.
     * @return string
     */
    virtual string classify(Classifiable c) = 0;
};


#endif //ASS1_CLASSIFIER_H
