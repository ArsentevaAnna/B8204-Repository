/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: КОНСТАНТИН
 *
 * Created on 22.05.2017, 20:22:44
 */

#include "newtestclass.h"
#include "Virtual.h"

class Rectangle : public Shape
{
private:

    float length;
    float width;

public:

    Rectangle(float _length, float _width)
    {
        type = 1;
        length = _length;
        width = _width;
    }

    float getSquare()
    {
        float result = length * width;
        return result;
    }

    void print()
    {
        cout << "Прямоугольник " << length << " " << width << endl;
    }
};

class Circle : public Shape
{
private:

    float radius;

public:

    Circle(float _radius)
    {
        type = 2;
        radius = _radius;
    }

    float getSquare()
    {
        float result = 3.14 * radius * radius;
        return result;
    }

    void print()
    {
        cout << "Круг " << radius << endl;
    }
};

class Square : public Shape
{
private:

    float side;

public:

    Square(float _side)
    {
        type = 3;
        side = _side;
    }

    float getSquare()
    {
        float result = side * side;
        return result;
    }

    void print()
    {
        cout << "Квадрат " << side << endl;
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass()
{
}

newtestclass::~newtestclass()
{
}

void newtestclass::setUp()
{
}

void newtestclass::tearDown()
{
}

void newtestclass::testGetSquare()
{
    ShapesProcessor shapesProcessor;
    Square S1(2);
    Rectangle S2(4, 3.14);
    Circle S3(3);
    shapesProcessor.add(S1);
    shapesProcessor.add(S2);
    shapesProcessor.add(S3);
    vector<float> result = shapesProcessor.getSquare();
    float c[3] = {2*2, 4*3.14, 3*3*3.14};
    CPPUNIT_ASSERT(result[0] == c[0] && result[1] == c[1] && result[2] == c[2] && result.size()==3);
}

void newtestclass::testMaxSquare()
{
    ShapesProcessor shapesProcessor;
    Square S1(2);
    Rectangle S2(4, 3.14);
    Circle S3(3);
    shapesProcessor.add(S1);
    shapesProcessor.add(S3);
    shapesProcessor.add(S2);
    Shape* result = shapesProcessor.maxSquare();
    float c = 3*3*3.14;
    CPPUNIT_ASSERT(result->getSquare() == c);
}

void newtestclass::testMinSquare()
{
    ShapesProcessor shapesProcessor;
    Square S1(2);
    Rectangle S2(4, 3.14);
    Circle S3(3);
    shapesProcessor.add(S1);
    shapesProcessor.add(S3);
    shapesProcessor.add(S2);
    Shape* result = shapesProcessor.minSquare();
    float c = 2*2;
    CPPUNIT_ASSERT(result->getSquare() == c);
}

void newtestclass::testSameSquare()
{
    ShapesProcessor shapesProcessor;
    Square S1(2);
    Rectangle S2(4, 3.14);
    Circle S3(2);
    shapesProcessor.add(S1);
    shapesProcessor.add(S3);
    shapesProcessor.add(S2);
    int result = shapesProcessor.sameSquare();
    CPPUNIT_ASSERT(result == 2);
}

void newtestclass::testSameSquareType()
{
    ShapesProcessor shapesProcessor;
    Square S1(2);
    Rectangle S2(4, 3.14);
    Circle S3(2);
    shapesProcessor.add(S1);
    shapesProcessor.add(S3);
    shapesProcessor.add(S3);
    shapesProcessor.add(S2);
    ShapesProcessor result = shapesProcessor.sameSquareType();
    vector<float> newresult = result.getSquare();
    float c = 2*2*3.14;
    CPPUNIT_ASSERT(newresult[0] == c && newresult[1] == c && newresult.size() == 2);
}

