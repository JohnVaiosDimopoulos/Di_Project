#ifndef SORT_JOIN_PRE_PROCESSOR_H
#define SORT_JOIN_PRE_PROCESSOR_H

#include "../Basis_Structs/Relation.h"
#include "../Initializer/Data_Table/Data_Table.h"

RelationPtr Get_Relation(Data_Table_Ptr);
void Print_Relation(RelationPtr);
void Delete_Relation(RelationPtr);

#endif //SORT_JOIN_PRE_PROCESSOR_H
