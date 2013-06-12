  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: e7.5-list.cpp
  // Implementation of class List for Exercise 7-5
  #include "e7.5-list.h"
  typedef  int T;
  namespace LIST_ITERATION_NAMESPACE {

    struct Link_ {  // struct, because Link is private
      T value_;
      Link_* next_;
      Link_(const T&, Link_*); // link with the next element
    };

    Link_::Link_(const T& t, Link_* h) : value_(t), next_(h) {}

    List::List() : head_(0), size_(0) {}

    List::~List() {
      T junk;
      while(size_ > 0)
         removeFirst(junk);
    }

    int List::size() const {
      return size_;
    }
    void List::ListIterator::insertAfter(const T& t)  throw(domain_error) {
        // insert after iterator
      if(current_ == 0)
        throw domain_error("trying to insert after empty iterator");   
      Link_* temp = new Link_(t, current_->next_);
      current_->next_ = temp; 
      ++myList_.size_;        
    }
    void List::ListIterator::insertBefore(const T& t) throw(domain_error) {       
        // insert before iterator
       if(current_ == 0 || myList_.head_ == 0)
         throw domain_error("trying to insert before empty iterator");  
       if(current_ == myList_.head_) {  // inserting in front
          myList_.insert(t);    
          return;
       }
        // find previous
       Link_* before;
       for(before  = myList_.head_; before->next_ != current_; before = before->next_)
         ;    
       Link_* temp = new Link_(t, current_);
       before->next_ = temp;
       ++myList_.size_;
    }
    void List::ListIterator::remove(T& t) throw(domain_error) {
           // remove element pointed to by iterator
       if(current_ == 0)
         throw domain_error("trying to remove for empty iterator");  
       // check if removing the first element
       if(current_ == myList_.head_) {
          t = myList_.head_->value_;
          Link_* temp = myList_.head_;
          myList_.head_ = temp->next_;
          delete temp;    
          current_ = myList_.head_;
          --myList_.size_;  
          return;
       }
       // find previous
       Link_* temp;
       for(temp  = myList_.head_; temp->next_ != current_; temp = temp->next_)
         ;
       t = current_->value_;
       temp->next_ = current_->next_;
       delete current_;
       current_ = temp->next_; 
       --myList_.size_;  
    }

    void List::insert(const T& t) {
      Link_* temp = new Link_(t, head_);
      head_ = temp;
      ++size_;
    }

    void List::removeFirst(T& t) throw(domain_error) {
      if(size_ == 0)
        throw domain_error("trying to remove from empty list");
      t = head_->value_;
      Link_* temp = head_;
      head_ = temp->next_;
      delete temp;
      --size_;
    }
 
    List::ListIterator::ListIterator(Link_* t, List& l) : current_(t), myList_(l) {}

    T& List::ListIterator::operator*() throw(domain_error) {
      if(current_ == 0)
         throw domain_error("trying to use * for empty iterator");
      return current_->value_;
    }
    const T& List::ListIterator::operator*() const throw(domain_error) {
      if(current_ == 0)
         throw domain_error("trying to use * for empty iterator");
      return current_->value_;
    }        
    List::ListIterator List::begin(){
      return List::ListIterator(head_, *this);
    }

    List::ListIterator List::end() {
      return ListIterator(0, *this);
    }

    List::ListIterator& List::ListIterator::operator++() throw(domain_error) { // prefix
     if(current_ == 0)
       throw domain_error("trying to use ++ for empty iterator");   
      current_ = current_->next_;
      return *this;
    }
    List::ListIterator operator++(List::ListIterator& i, int) throw(domain_error) { // postfix
      List::ListIterator temp(i);
      ++i;
      return temp;
    }
    bool operator==(const List::ListIterator& i, const List::ListIterator& j) {
      return i.current_ == j.current_;
    }

    bool operator!=(const List::ListIterator& i, const List::ListIterator& j) {
      return !(i == j);
    }

  }
