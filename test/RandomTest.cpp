#include <iostream>
#include "Random.h"
#include "UnitTestAssert.h"
using namespace std;

using namespace UnitTest;

void FirstTry()
{
      Random random(-314159);
      UnitTest::Assert::AreEqual(119318998, random.NextInt());
}

void SecondTry()
{
      Random random(-314159);
      for (int i = 0; i < 134; ++i) random.NextInt();
      UnitTest::Assert::AreEqual(748103812, random.NextInt(0x55555555));
}

int main()
{
      FirstTry();
      SecondTry();
}
