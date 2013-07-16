Assignment 4
------------

Based on the book *C++ Programming with Design Patterns Revealed*

Code tested with clang++ 3.2, but g++ 4.5 and up should also work.  
Run `make` to build the executables.

---

#### Exercise 6.3
> Use the abstract factory design pattern to implement a program working with
> file encryption. The program is similar to the one from example 6.1, but this
> time there are two products representing files encrypted using two different
> algorithms.
> The first encryption algorithm: an integer N (0 < N < 128) is added to the
> ordinal (aka ASCII) value of each character. The user supplies the encryption
> code N at runtime.
> The second encryption algorithm: the user provides a keyword; an input file is
> divided into blocks equal to the size of the word, and then the i-th character
> in that block is encrypted by adding the ASCII code of the i-th character in
> the keyword. This is a variation of the Vigenère cipher.
> Also provide the corresponding decryption algorithms.

The more dependencies you have, the more difficult it is to maintain and modify
your code. Use creational design patterns to avoid the problem.
The **abstract factory design pattern** minimizes the dependencies between
various elements of your program; dependency on object creation is limited to a
single class. 

The abstract factory pattern encapsulates the creation of objects in another
class and uses the interface of this class to get new objects whenever
necessary. Any future changes to the creational process will be isolated to the
class that produces objects.

The object that creates other objects is the factory, and the object being
created is a product. The factory is responsible for producing a specific
product, accomplished with the factory method. The factory method has
a (typically string) parameter used to decide which product it should produce.

Your code should have at least two classes when using this pattern:
(1) a factory class (which may be abstract), and (2) an abstract product class
(which is the base class for all products).
The client would create a factory object and use its factory method to create
various kinds of products. This avoids hard-coding concrete product names. E.g.

```cpp
// User of pattern never creates objects directly, instead gets a factory to
// create concrete products. String determines which concrete factory to use.
AbstractFactory* factory = AbstractFactory::getFactory(string); // instantiating operation: returns a concrete factory
AbstractProduct* product = factory->createProduct(string); // factory method: returns a concrete product
product->doSomething();
```
The factory method is often useful in combination with the template method
pattern (which defines an algorithm in terms of abstract operations). If using a
template method, the factory method should be hidden from the client (i.e.
private) and there shouldn't be an instantiating operation (i.e. getFactory()).
The client calls the template method instead, which uses the factory method to
create and use a product.

Typically, you need at most one instance per concrete factory in your
application, so concrete factories are often implemented as singletons.

**Note:** The difference between the abstract factory pattern and factory pattern is
that the former creates concrete products via dedicated concrete factories based
off of an abstract factory, whereas the latter creates concrete products via
a single factory.

**Keywords:** abstract factory pattern, template method pattern, cryptography,
              decltype, ...

---

#### Exercise 6.10
> Use the object design pattern to implement exercise 6.9 (code provided).

An important goal for code is reusability. Programming to an interface, not an
implementation helps with this. The idea is to have two hierarchies,
abstraction classes and implementation classes, and they are bridged through
a delegate. The client uses the abstraction, and the implementation is hidden.
This minimizes the dependencies between subsystems. Examples of practical
benefits include reducing compilation time, or clients can use existing API
calls when a new API version is released.

The **adapter design pattern** is used to create a new class interface by
converting an existing interface. The adapter lets two classes work together,
even though they have _incompatible_ interfaces. This is useful when an
application needs _almost_ the same interface but with some minor differences.
Consider this pattern when modifying the existing class interface is not a
feasible solution.

There are two kinds of adapters: **class adapters** and **object adapters**.
Object adapters are recommended over class adapters, especially if you need to
adapt several existing classes.

The new interface will be a pure abstract class, and is implemented using the
implementation provided by the existing class. You need to write an _adapter
mixin class_ to connect the new and old interface.
**The adapter class will provide the implementation of the new interface,
building on top of the old interface's implementation.**
The structure of this class differs whether you use a class or object adapter.
The new interface and the adapter class should use the same namespace.

<dl>
  <dt>Class adapter</dt>
  <dd>
    The adapter class uses multiple inheritance: it inherits the new interface
    and the implementation of the old interface (via private inheritance).

    Implementations of the old interface are used by refering the base class,
    e.g. `namespace::OldClass::operation();`
  </dd>
  <dt>Object adapter</dt>
  <dd>
    The adapter class only inherits the new interface and uses object
    composition. It contains a private encapsulated member (e.g. a pointer to
    the old class and is often called `adaptee_`). The constructor takes in (a
    pointer to) an instance of the old class and uses it to initialize the class
    member.

    Implementations of the old interface are used by having the composited
    object (e.g. "adaptee") call the operations.
  </dd>
</dl>

**Note:** Structural design patterns (e.g. bridge and adapter patterns) describe
how to compose existing objects and classes to form new structures.

**Keywords:** (object) adapter pattern, adapting an existing class
