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

void newtestclass::testTextToBase64()
{
    string input = TextToBase64("Hello, World!");
	string output = "SGVsbG8sIFdvcmxkIQ==";
	CPPUNIT_ASSERT(!strcmp(input, output)); 
    input = TextToBase64("1");
	output = "MQ==";
	CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("12");
	output = "MTI=";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("123");
	output = "MTIz";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("1234");
	output = "MTIzNA==";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("12345");
    output = "MTIzNDU=";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("123456");
	output = "MTIzNDU2";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = TextToBase64("");
	output = "";
	CPPUNIT_ASSERT(!strcmp(input, output));
}

void newtestclass::testBase64ToText()
{
    string input = Base64ToText("SGVsbG8sIFdvcmxkIQ==");
	string output = "Hello, World!";
	CPPUNIT_ASSERT(!strcmp(input, output)); 
    input = Base64ToText("MQ==");
    output = "1";
    CPPUNIT_ASSERT(!strcmp(input, output)); 
    input = Base64ToText("MTI=");
	output = "12";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = Base64ToText("MTIz");
	output = "123";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = Base64ToText("MTIzNA==");
	output = "1234";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = Base64ToText("MTIzNDU=");
	output = "12345";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = Base64ToText("MTIzNDU2");
	output = "123456";
    CPPUNIT_ASSERT(!strcmp(input, output));
    input = Base64ToText("");
	output = "";
    CPPUNIT_ASSERT(!strcmp(input, output));
	input = Base64ToText("ФШДАРЛОАФ");
	output = "";
    CPPUNIT_ASSERT(!strcmp(input, output));
}
