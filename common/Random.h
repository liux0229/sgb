#include <vector>
#include "core.h"


// TODO: quality items:
// Namespace
// Assert
// Remove magic numbers
// Test non-cycle behavior
// Print random map
// Add trace capability (i.e. remove direct reference to iostream)
// wide char
// UNIT test loader
// Has been read since reading

class Random
{
      DENY_COPY(Random);
public:
      explicit Random(int seed);

      // return an int in [0, 2^31)
      int NextInt()
      {
            return *next_ >= 0 ? *next_-- : NextCycle();
      }

      // return an int in [0, m)
      int NextInt(int m) 
      { 
            Assert::CodingErrorIfNot(m > 0 && static_cast<unsigned>(m) < (1UL << 31), "m out of range");
            unsigned x = 1UL << 31;
            unsigned t = x - (x % m);
            int r;
            do
            {
                  r = NextInt();
            } while (t <= static_cast<unsigned>(r));
            return r % m; 
      }

private:
      void Initialize(int seed);

      void Warmup();

      int NextCycle();

      int ModDiff(int a, int b)
      {
            return (a - b) & 0x7fffffff;
      }

      std::vector<int> A_;
      int *next_;
};
