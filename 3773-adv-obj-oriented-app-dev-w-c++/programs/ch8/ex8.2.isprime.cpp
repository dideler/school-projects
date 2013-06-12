  // File: ex8.1.isprime.cpp
#include <utility>
#include <functional>
  template<typename Iterator, typename Predicate>
  // ElementType is a model of Equality Comparable 
  // Predicate is a model of a boolean Unary Functor
  Iterator find_if(Iterator first, Iterator last, 
        const Predicate& pred) {
    Iterator aux;
    for(aux = first; aux != last; ++aux) 
      if(pred(*aux))  // found
        break; 
    return aux;
  }

  struct isPrime : public unary_function<int, bool> {
    bool operator()(int) const;
  };

  #include <cmath>
  bool isPrime::operator()(int n) const {  
    int root, divisor;
    if(n < 4)
        return n >= 1;
    if(n % 2 != 1)  // even
        return false;
    root = static_cast<int>(sqrt((double) n) + 0.5);
    for(divisor = 3; divisor <= root && n%divisor != 0;)
      divisor += 2;
    return divisor > root;
  }

