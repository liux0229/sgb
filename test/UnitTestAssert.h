#include <iostream>

namespace UnitTest
{
      class Assert
      {
      public:
            template<typename T>
            static void AreEqual(T const& expected, T const& actual)
            {
                  if (expected != actual)
                  {
                        std::cerr << "Failed; expected: " << expected << "; actual: " << actual << std::endl;
                  }
            }
      };
}
