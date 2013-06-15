Assignment 3
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Code tested with clang++ version 3.2.
g++ (minimum GCC 4.5) should also work.  
Run `make` to build the executables.

---

#### Exercise 5.11
> Write the class `Queue`, similar to the class `IntStack` from example 5.3,
> in which the elements of the queue are stored in an array. This class should
> be stored in a namespace and use exception handling.

TIPS:
- code provided for example 5.3 (which is based on example 3.5)
- exercise 4.9 (code provided) is similar, has namespaces but no exception
  handling

**Keywords:** namespaces, exception handling, queue

---

#### Exercise 5.13
> Write a class derived from the class `BenchmarkClass` from example 5.4 to
> benchmark two sorting algorithms (bubble and quick sort) for `double` values
> stored in an array.

This class uses the **template method design pattern**, a class behavioural
pattern (i.e. describes class behaviour). This pattern describes how to define
an algorithm so that the specification of some of its steps is deferred to the
derived classes. This means the base class is an abstract class (in C++ this
requires at least one pure virtual method, aka "primitive operation").

The template method should not be overridden, so it's not defined as `virtual`
and is public. The template method -- e.g. sort()` -- uses abstract
(primitive) operations -- e.g. `compare()` that are declared in the abstract
base class but implemented in the derived classes. These abstract operations are
(pure) and should be private or protected so the client cannot directly call them.

TODO:
- `compare()`, primitive operation that compares two elements
- abstract base class has template method `sort()` that uses `compare()`
- various derived classes define different ways of comparing elements

**Keywords:**
