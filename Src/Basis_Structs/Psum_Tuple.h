#ifndef SORT_JOIN_PSUM_TUPLE_H
#define SORT_JOIN_PSUM_TUPLE_H
#include <stdint.h>

struct Psum_Tuple{
  uint64_t value;
  uint64_t sum;
};

typedef struct Psum_Tuple* Psum_Tuple_Ptr;

#endif
