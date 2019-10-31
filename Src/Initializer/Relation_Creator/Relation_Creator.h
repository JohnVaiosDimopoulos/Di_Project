#ifndef SORT_JOIN_RELATION_CREATOR_H
#define SORT_JOIN_RELATION_CREATOR_H

#include <stdio.h>
#include <stdint.h>
#include "../../Basis_Structs/Relation.h"

RelationPtr Create_Relation(int);
RelationPtr Set_up_Relation(FILE *);
int Get_Num_of_elements(RelationPtr);
Tuple_Ptr Get_Tuples(RelationPtr Relation);
void Delete_Relation(RelationPtr);

//For exhibition purposes only
void Print_Relation(RelationPtr Relation);

#endif //SORT_JOIN_RELATION_CREATOR_H
