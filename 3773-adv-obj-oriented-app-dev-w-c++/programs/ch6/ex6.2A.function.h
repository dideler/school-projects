  // File: ex6.2A.function.h

  #ifndef FUNCTIONA_H
  #define FUNCTIONA_H
  class Function { // abstract
  public:
    virtual void display() = 0; // derived class responsibility
    virtual Function* factoryMethod(string) const;
  protected:
    Function(string);
    Function(const Function&);
    virtual ~Function();
    string s_;
  };
  #endif
