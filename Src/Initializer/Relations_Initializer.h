#ifndef SORT_JOIN_RELATIONS_INITIALIZER_H
#define SORT_JOIN_RELATIONS_INITIALIZER_H

#include "Relation_Creator/Relation_Creator.h"
#include "Argument_Manager.h"

void Initialize(Arg_Manager_Ptr, RelationPtr *Relation_1, RelationPtr *Relation_2);
void Initialize_Relation(RelationPtr *Relation, const char *filename);

#endif //SORT_JOIN_RELATIONS_INITIALIZER_H
