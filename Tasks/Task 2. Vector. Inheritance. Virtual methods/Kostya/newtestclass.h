/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.h
 * Author: КОНСТАНТИН
 *
 * Created on 22.05.2017, 20:22:44
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testGetSquare);
    CPPUNIT_TEST(testMaxSquare);
    CPPUNIT_TEST(testMinSquare);
    CPPUNIT_TEST(testSameSquare);
    CPPUNIT_TEST(testSameSquareType);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testGetSquare();
    void testMaxSquare();
    void testMinSquare();
    void testSameSquare();
    void testSameSquareType();

};

#endif /* NEWTESTCLASS_H */

