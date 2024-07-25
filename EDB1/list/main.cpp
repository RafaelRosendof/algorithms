#include "list.h"

//init is wring, is giving shit
int main() {
    List<int> myList;
    myList.push_back(10);
    myList.push_front(20);
    myList.push_back(30);
    myList.printList(); // Should output 20 10 30

    myList.pop_front();
    myList.printList(); // Should output 10 30

    return 0;
}