/*  
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: КОНСТАНТИН
 *
 * Created on 18.04.2017, 20:50:30
 */

#include "newtestclass.h"
#include "Base.h"
#include <cstring>
#include <cstdlib>

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

void newtestclass::testBase64ToText()
{
    string my = "";
    my+=(unsigned char) (rand() % 255);
    Base64 base64;
    srand(time(NULL));
    string result = base64.Base64ToText(base64.TextToBase64(my));
    for (int i = 0; i < 100; i++)
    {
        CPPUNIT_ASSERT(!strcmp(my.c_str(), result.c_str()));
        CPPUNIT_ASSERT(strcmp(base64.TextToBase64(my), base64.Base64ToText(base64.TextToBase64(my)) );
        my += (unsigned char) rand() % 255;
        result = base64.Base64ToText(base64.TextToBase64(my));
    }
}

