Assignment 1
------------

Based on the book *C++ Programming with Design Patterns Revealed*

#### Exercise 3.3
> Write a class `Lines` that provides the following four operations on lines:
> -test if two lines are parallel
> - test if two lines are perpendicular
> - find the intersection of two lines (assume not called if already parallel)
> - find shortest distance between a line and a point

I provided many additional operations that are needed for the above four operations,
but made them private so they're not part of the (public) interface. 

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
features such as inheritance, polymorphism, abstract classes, scoped enums,
friends, and operator overloading. It's not meant to be graded.
I included it because feedback is always appreciated :).

#### Exercise 3.10
> Repeat exercise 3.9 but use pointers to represent a flower and a book.
