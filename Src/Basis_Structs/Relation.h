#ifndef SORT_JOIN_RELATION_H
#define SORT_JOIN_RELATION_
#include "Tuple.h"

typedef struct {
  Tuple_Ptr tuples;
  uint64_t num_of_tuples;
} Relation;

typedef Relation* RelationPtr;

#endif //SORT_JOIN_RELATION_H
