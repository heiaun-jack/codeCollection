///////////////////////////////////////////////////////////////
// Singleton.cpp - share single instance                     //
//                                                           //
// Platform:    Visual Studio 2013, Dell XPS 2720            //
// Application: Support for class Projects                   //
//              CSE687 - Object Oriented Design, Spring 2014 //
// Author:      Jim Fawcett, CST 4-187, Syracuse University  //
//              jfawcett@twcny.rr.com, 315 443-3948          //
///////////////////////////////////////////////////////////////

#ifdef TEST_SINGLETON

#include "Singleton.h"
#include <iostream>

class Cosmetic {
public:
  ~Cosmetic() { std::cout << "\n\n"; }
} cosmetic;

class Test
{
public:
  Test() { std::cout << "\n  constructing instance of test"; }
  ~Test() { std::cout << "\n  destroying instance of test"; }
  void doOp() { std::cout << "\n  test doing some work"; }
};

void getAnotherPointer()
{
  Test* pTest = Singleton<Test>().instance();
  pTest->doOp();
}
int main()
{
  std::cout << "\n  Testing Singleton Instances";
  std::cout << "\n =============================";

  Singleton<Test> singleTest;
  Test* pTest = singleTest.instance();
  pTest->doOp();
  getAnotherPointer();
}

#endif