Assignment 5
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Code tested with clang++ 3.2. Run `make` to build the executables.

---

#### Exercise 7.5
> Modify example 7.1 (list iterator) by adding exception handling.
> In addition, add functions to insert elements before and after the value
> pointed to by the iterator and to delete the value pointed to by the iterator.

Note that exercise 7.5 was one of the provided exercises, and therefore I was
told not to re-do it.

**Keywords:** iterators, friends, namespace, exception handling, helpers,
              overloading operators

---

#### Exercise 7.11
> Implement a template class `List` (base your design on examples 7.3 and 7.4).
> Do not use exception handling.
> Use the same testing criteria as in exercise 7.10.
> In addition, test your class with a list of lists of integers.

For the template code, I put the declarations and definitions in the header
file, instead of splitting them up between the header and source files.
This is to avoid linker errors. Note that alternative workarounds exist.
For more info:
- http://www.parashift.com/c++-faq-lite/separate-template-fn-defn-from-decl.html
- http://stackoverflow.com/questions/3749099/why-should-the-implementation-and-the-declaration-of-a-template-class-be-in-the

I also avoided using nested/member classes/structs because it unnecessarily
overcomplicates the code in my opinion.

**Keywords:** templates (generic/parameterized classes and member operations),
              iterators, lists, overloading, friends, helpers, namespace
