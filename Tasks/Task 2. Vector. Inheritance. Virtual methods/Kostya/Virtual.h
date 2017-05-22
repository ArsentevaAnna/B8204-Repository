#ifndef HEADER_H
#define HEADER_H

#include <map>

using namespace std;

class Shape {
public:

    int type;

    virtual float getSquare() = 0;
    virtual void print() = 0;
};

class ShapesProcessor {
private:

    vector<Shape*> vec;
    static bool compare1(Shape* i, Shape* j);
    static bool compare2(pair<float, int> i, pair<float, int> j);
public:
    void add(Shape &S);
    void clear();
    vector<float> getSquare();
    Shape* maxSquare();
    Shape* minSquare();
    int sameSquare();
    ShapesProcessor sameSquareType();
    void print();

};
#endif