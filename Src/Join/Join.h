#ifndef SORT_JOIN_DATA_JOIN_H
#define SORT_JOIN_DATA_JOIN_H

#include <stdio.h>
#include <stdint.h>
#include "../Initializer/Relation_Creator/Relation_Creator.h"
#define LIMIT (1024 * 1024)
#define SIZE_OF_ARRAY_TUPLE (2 * 8)
#define LIST_SIZE ((LIMIT-12)/SIZE_OF_ARRAY_TUPLE)


typedef struct Result_List* List_Ptr;
typedef struct List_node* Node_Ptr;

void Join(RelationPtr, RelationPtr);

#endif //SORT_JOIN_RELATION_CREATOR_H
