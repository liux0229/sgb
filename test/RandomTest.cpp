#include <iostream>
#include "Random.h"
using namespace std;

// TODO: convert this into an actual unit test

int main()
{
      Random random(-314159);
      int next = random.NextInt();
      int expected = 119318998;
      if (next != expected)
      {
            cerr << "Failure on first try. Expected: " << expected << "; Actual: " << next << endl;
      }

      for (int i = 0; i < 133; ++i) random.NextInt();

      next = random.NextInt(0x55555555);
      expected = 748103812;
      if (next != expected)
      {
            cerr << "Failure on second try. Expected: " << expected << "; Actual: " << next << endl;
      }
}
