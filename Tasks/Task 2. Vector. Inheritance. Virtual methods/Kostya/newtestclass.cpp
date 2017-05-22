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
    vector<float> result = shapesProcessor.getSquare();
    if (true /*check result*/)
    {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testMaxSquare()
{
    ShapesProcessor shapesProcessor;
    Shape* result = shapesProcessor.maxSquare();
    if (true /*check result*/)
    {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testMinSquare()
{
    ShapesProcessor shapesProcessor;
    Shape* result = shapesProcessor.minSquare();
    if (true /*check result*/)
    {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSameSquare()
{
    ShapesProcessor shapesProcessor;
    int result = shapesProcessor.sameSquare();
    if (true /*check result*/)
    {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSameSquareType()
{
    ShapesProcessor shapesProcessor;
    ShapesProcessor result = shapesProcessor.sameSquareType();
    if (true /*check result*/)
    {
        CPPUNIT_ASSERT(false);
    }
}

