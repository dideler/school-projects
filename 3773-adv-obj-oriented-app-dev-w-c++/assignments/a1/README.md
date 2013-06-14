Assignment 1
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Built and tested with gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5).
You need minimum GCC 4.5, otherwise try Clang.  
Run `make` to build the executables.

#### Exercise 3.3
> Write a class `Lines` that provides the following four operations on lines:
> - test if two lines are parallel
> - test if two lines are perpendicular
> - find the intersection of two lines (assume not called if already parallel)
> - find shortest distance between a line and a point

I provided many additional operations that are needed for the above four operations,
but made them private so they're not part of the (public) interface. 

**Keywords:** class organization, (custom) exception handling, friendship, (object) composition, geometry, operator (<<)  overloading, assertion, C++11  features (auto keyword, range-based loops)

#### Exercise 3.9
> Design and implement the following classes:
> - `Flower`, with three attributes
>   1. name
>   2. price
>   3. colour (should be of enumeration type)
> - `Book`, with two attributes
>   1. name
>   2. price
> - `Gift`, with two attributes (using nested objects)
>   1. flower
>   2. book
>
> Carefully design the interfaces for these classes and write a program to test them.

I made two versions for exercise 3.9, ex3.9 and ex3.9v2.
The second version was made so I could become more familiar with advanced C++
features and is not meant to be graded, but feedback is appreciated.

**Keywords (ex3.9):** enums, composition (aka nested objects)

**Keywords (ex3.9v2):** inheritance, polymorphism, scoped enums (C++11), abstract class, friendship, operator overloading

#### Exercise 3.10
> Repeat exercise 3.9 but use pointers to represent a flower and a book.

**Keywords:** enums, composition, pointers, copy constructor, copy assignment operator, destructor
