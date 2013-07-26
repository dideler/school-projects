// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include "ex7.4-array1.h"

namespace ARRAY_NAMESPACE
{

template <typename T>
bool operator==(const Array<T>& ar1, const Array<T>& ar2)
{
  for (int i = 0; i < ar1.size(); i++)
    if (!(ar1[i] == ar2[i])) return false;
  return true;
}

template <typename T>
bool operator!=(const Array<T>& ar1, const Array<T>& ar2)
{
  return !(ar1 == ar2);
}

} // namespace ARRAY_NAMESPACE
