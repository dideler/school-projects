Assignment 3
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Code tested with clang++ 3.2, but g++ 4.5 and up should also work.  
Run `make` to build the executables.

---

#### Exercise 5.11
> Write the class `Queue`, similar to the class `IntStack` from example 5.3,
> in which the elements of the queue are stored in an array. This class should
> be stored in a namespace and use exception handling.

**Keywords:** namespaces, exception handling, queue, std::copy

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
If you're writing an abstract class and using polymorphism, it's natural that
the template method pattern follows.

The template method should not be overridden, it's not defined as `virtual`
and it's public. The template method calls abstract (primitive) operations
(which are declared in the abstract base class but implemented in the derived
classes). These abstract operations are pure virtual in the base class
and should be private or protected so the client cannot directly call them.

**Keywords:** template method pattern, inheritance, sorting (quicksort,
mergesort), timing benchmarks (w/ std::chrono), std::shuffle
