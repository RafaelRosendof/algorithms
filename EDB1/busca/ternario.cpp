#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using value_type = int;

template <typename T, size_t size>
std::string to_string(std::array<value_type, size> A) {
  std::string results = "]";
  for (size_t i{0}; i < A.size(); ++i) {
    results += std::to_string(A[i]);
    if (i != size - 1) {
      results += ", ";
    }
    results += "]";
  }
}

template <typename T, size_t size>
value_type * ternario(std::array<T, size> &arr, value_type *begin, value_type *end, value_type target) {

  /*
  Ternary search, first need to sort the array

  Second need to divide the array by 3

  compare with the target

  Repeat or break
  */
  value_type *f = begin, *l = end;

  std::sort(arr.begin(), arr.end());

  //value_type *mid1 = f + (l - f) / 3;
  //value_type *mid2 = l - (l - f) / 3;

  // if (target == mid1) { mid2 = mid1 - 1 e mid1 = arr.begin }
  while (f < l) {
    value_type *mid1 = f + (l - f) / 3;
    value_type *mid2 = l - (l - f) / 3;

    if (*mid1 == target) {
      return mid1;
    }
    if (*mid2 == target) {
      return mid2;
    }
    if (*f == target) {
      return f;
    }

    if (target < *mid1) {
      l = mid1;
    }

    else if (target > *mid2) {
      f = mid2 + 1;
    }

    else {
      f = mid1 + 1;
      l = mid2;
    }
  }
  return end;
}


int main(){

    std::array<int,12> figas = {1,43,56,76,78,90,98,7,64,31,34,56};
    value_type target{90};
    int *teste = ternario(figas , figas.begin() , figas.end(), target);

    std::cout << *teste << " achou o : " << target <<  " " <<std::endl; 
    return 0;
}