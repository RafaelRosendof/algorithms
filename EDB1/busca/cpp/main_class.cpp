#include "head.h"

namespace sa {

class busca {
public:
  value_type *lsearch(value_type *begin, value_type *end, value_type target) {
    value_type *f = begin, *l = end;

    while (f <= l) {
      if (*f == target) {
        return f;
      }

      else {
        f++;
      }
    }
   // free(l);
   // free(f);
    return end;
  };

  value_type *bsearch(value_type *begin, value_type *end, value_type target) {
    value_type *f = begin, *l = end;

    while (f <= l) {
      value_type *meio = f + (l - f) / 2;

      if (*begin == target) {
        return begin;
      }
      if (*meio == target) {
        return meio;
      }

      else if (*meio < target) {
        f = meio + 1;
      } else {
        l = meio - 1;
      }
    }
    return end;
  }


    value_type * bsearch_rec(value_type *begin , value_type *end , value_type target){
        value_type * f = begin , * l = end;
        while(f <= l){

            value_type *meio = f + (l - f) / 2;

            if(*meio == target){return meio;}

            else if(*meio < target){
                return bsearch_rec(meio + 1, l, target);
            }
            else{return bsearch_rec(f, meio - 1,  target);}
        }
        return end;
    }
    //this can be a .hpp why?, the .cpp can be only a code for asserts and creations of arrays. 
    value_type * ternario(value_type* begin , value_type* end , value_type target){
        value_type *f = begin , *l = end;
        if(*begin == target){return begin;}
        while(f < l){
            value_type * mid1 = f + (l - f) / 3;
            value_type * mid2 = mid1 + (l - f) / 3;

            //let's gonna do some checking
            if(*mid1 == target){return mid1;}
            if(*mid2 == target){return mid2;}

            if(*mid1 > target){l = mid1;}

            else if(target > *mid2){f = mid2+1;}

            else{
                l = mid2;
                f = mid1+1;
                }

            }
        return end;
        }
    };
} // namespace sa
