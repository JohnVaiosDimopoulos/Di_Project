#ifndef SORT_JOIN_HIST_TUPLE_H
#define SORT_JOIN_HIST_TUPLE_H
#include <stdint.h>

struct Hist_Tuple{
  uint64_t value;
  uint64_t quantity;
};

typedef struct Hist_Tuple* Hist_Tuple_Ptr;

#endif //SORT_JOIN_TUPLE_H
