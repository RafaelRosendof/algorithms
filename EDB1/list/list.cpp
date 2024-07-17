#include <iostream>
#include <algorithm>

//todo: put more libs if i need
//

template<typename Object>

class List {

private:
  struct Node{

  }

public:
  
  class const_iterator{

  };

  class iterator : public const_iterator{

  };


public:

  List(); // 3.16

  List(const List & rhs) = //3.16;
  List &operator=(List && rhs) = default;
  List &operator=(const List &) = default;
  ~List();


  iterator begin() {return {head -> next} ; }

  const_iterator begin() const{ return {head -> next}; }

  iterator end() {return {tail} ; }

  const_iterator end() const { return {tail} ; }


  int size() const {return theSize;}
  
  bool empty() const {return size() == 0;}

  void clear(){
    while(!empty){
      pop_front();
    }
  }  

  Object & front(){
    return *begin();
  }

  const Object & front(){
    return const *begin ;//is correct?
  }

  Object & back(){
    return *--end();
  }
  const Object & back(){
    const return *--end();
  }

  void push_front(const  Object & x){
    insert(begin() , x);
  }

  void push_front(Object && x){
    insert(begin() , std::move(x));
  }

  //todo push back e pop back
  
};

List::List() {
}

List::~List() {
}
