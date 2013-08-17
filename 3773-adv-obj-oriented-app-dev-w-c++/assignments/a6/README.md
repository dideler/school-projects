Assignment 6
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Code tested with clang++ 3.2. Run `make` to build the executables.

---

#### Exercise 8.5
> Implement a [wrapper] class, `SafeList`, that is derived from the STL class
> `list` and uses exception handling.

---

#### Exercise 8.9
> Implement a class, `Point`, that represents a point in a three-dimensional
> space. Carefully design the interface for this class, and include functions
> that appear to be useful for operating on points. Then use this class and the
> STL class `list` to write a class representing a list of points.

I decided to make my `PointList` class (which represents a list of points)
derive from my `SafeList` class from exercise 8.5 (see above), which in turn is
derived from the STL class `list`. It's a good reuse of code in my opinion, but
if this is not what the exercise intended, then I'll rewrite my PointList class.
