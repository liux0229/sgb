#include <iostream>
#include "Random.h"
using namespace std;

Random::Random(int seed)
      : A_(56, -1),
        next_()
{
      Initialize(seed);
      Warmup();
}

void Random::Initialize(int seed)
{
      seed &= 0x7fffffff;
      A_[55] = seed;
      int prev = seed;
      int next = 1;
      for (int i = 21; i; i = (i + 21) % 55)
      {
            A_[i] = next;

            // next = prev - next - (seed >> 1) (cyclic shift) mod M
            if (seed & 1) seed = (seed >> 1) + (1 << 30);
            else seed >>= 1;

            next = ModDiff(prev, next);
            next = ModDiff(next, seed);

            prev = A_[i];
      }

      // for (int i = 1; i <= 55; i++)
      // {
      //      cout << i << ": " << A_[i] << endl;
      // }
}

void Random::Warmup()
{
      int count = 5;
      while (count-- > 0) NextCycle();
}

inline int Random::NextCycle()
{
      // recurrence: A_[n] = (A_[n - 55] - A_[n - 24]) % M
      int i, j;
      for (i = 1, j = 32; j <= 55; ++i, ++j) A_[i] = ModDiff(A_[i], A_[j]);
      for (j = 1; i <= 55; ++i, ++j) A_[i] = ModDiff(A_[i], A_[j]);
      
      next_ = &A_[54];
      return A_[55];
}
