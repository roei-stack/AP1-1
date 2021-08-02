//
// Created by user on 7/31/2021.
//

#ifndef ASS1_CLASSIFIABLE_H
#define ASS1_CLASSIFIABLE_H

#include <string>
using namespace std;

/**
 * interface of an classifiable object.
 */
class Classifiable {
public:
    /**
     * returns the classification of this.
     * @return  string
     */
    virtual string getClassification() const = 0;

    /**
     * returns the distance between this and other.
     * the distance can be Euclidean, Manhattan, Hamming, etc.
     * @param other - an appropriate Classifiable such that
     *     this knows how to calculate the distance from other.
     *     probably, other will have to be from the same type as this.
     *     if other's type won't be appropriate, an exception may be thrown.
     * @return double
     */
    virtual double getDistance(const Classifiable& other) const = 0;

    virtual void setValues(double width, double sepalLength, double sepalWidth, double petalLength,
                   const string& classification) = 0;

    /**
     * virtual destructor.
     */
    virtual ~Classifiable() = default;
};


#endif //ASS1_CLASSIFIABLE_H
