//includes

#include <array>
#include <iostream>
#include <string>
#include <cstddef>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <vector>

#ifndef SEARCHING_H 
#define SEARCHING_H


namespace sa{
    //define value_type = int
    using value_type = int;

    value_type * lsearch(value_type* begin , value_type* end , value_type target);

    value_type * bsearch(value_type* begin , value_type* end , value_type target);

    value_type * bsearch_rec(value_type* begin , value_type* end , value_type target);

    value_type * ternario(value_type* begin , value_type* end , value_type);
}

#endif