#include <vector>


// TODO: quality items:
// Namespace
// A_ssert
// Deny copy
// Remove magic numbers
// Test non-cycle behavior
// Print random map
// Add trace capability (i.e. remove direct reference to iostream)

class Random
{
public:
      Random(int seed);

      // return an int in [0, 2^31)
      int NextInt()
      {
            return *next_ >= 0 ? *next_-- : NextCycle();
      }

      // return an int in [0, m)
      int NextInt(int m) 
      { 
            // TODO: check m
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
