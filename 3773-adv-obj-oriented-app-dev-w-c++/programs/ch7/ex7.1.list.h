  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex7.1.list.h
#ifndef EX7_1_LIST_H
#define  EX7_1_LIST_H  
  namespace LIST_ITERATION_NAMESPACE {

    typedef  int T;
    struct Link_;   // declaration

    class List {
	 
    public:
      List();
      virtual ~List();

      void insert(const T&); // insert in front
      bool remove(T&);    // delete first; return true if successful
      int size() const;   // size of the list
		
      class ListIterator {
	  friend  bool operator==(const ListIterator&, const ListIterator&);
      public:
        ListIterator(Link_* = 0);
        T& operator*();
        const T& operator*() const;
        ListIterator& operator++();
      private: 
        Link_* current_;
      };
	
      ListIterator begin() const;
      ListIterator end() const;
  
    private:
      List(const List&);
      List& operator=(const List&);
      Link_* head_;
      int size_;
    };  // end of List

    // declarations of helpers
    List::ListIterator operator++(List::ListIterator&, int);  // postfix
    bool operator==(const List::ListIterator&, const List::ListIterator&) ;
    bool operator!=(const List::ListIterator&, const List::ListIterator&) ;

  }
#endif
