#include <cmath>
#include <utility>
#include <functional> // std::unary_function

// ElementType is a model of Equality Comparable 
// Predicate is a model of a boolean Unary Functor
template<typename Iterator, typename Predicate>
Iterator find_if(Iterator first, Iterator last, const Predicate &pred)
{
  Iterator aux;
  for (aux = first; aux != last; ++aux)
    if (pred(*aux)) break; // found
  return aux;
}

// NOTE: unary_function is deprecated since C++11.
struct isPrime : public std::unary_function<int, bool>
{
  bool operator()(int) const;
};

bool isPrime::operator()(int n) const
{
  if (n < 4) return n >= 1;
  if (n % 2 == 0) return false;
  int root = static_cast<int>(sqrt(static_cast<double>(n)) + 0.5);
  int divisor = 3;
  while ((divisor <= root) && (n % divisor != 0)) divisor += 2;
  return divisor > root;
}
