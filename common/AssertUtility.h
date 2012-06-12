#include <cassert>
#include <string>
#include <iostream>

class Assert
{
public:
      static void CodingErrorIf(bool condition, std::string const& message)
      {
            if (condition)
            {
                  // TODO: fix error message
                  std::cerr << message << std::endl;
                  assert(false);
            }
      }
      static void CodingErrorIfNot(bool condition, std::string const& message)
      {
            CodingErrorIf(!condition, message);
      }
};
