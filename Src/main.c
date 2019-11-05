#include "Initializer/Argument_Manager.h"
#include "Initializer/Relation_Creator/Relation_Creator.h"
#include "Initializer/Relations_Initializer.h"
#include "Relation_Sorting/Relation_Sorting.h"

void join(RelationPtr A, RelationPtr B) {
  Tuple_Ptr A1, A2, B1, B2;
  A1 = A2 = A->tuples;
  B1 = B2 = B->tuples;
  
  int i = 0;
  int cntA = 0;
  int cntB = 0;
  while(1) {
    if(A2->element < B2->element) {
//      printf("element %llu does not exit in B\n", A2->element);
      cntA++;
//      printf("cntA = %d ", cntA);
      if(cntA == A->num_of_tuples)
      	break;
      A2++;
      A1 = A2;
//      printf("move A2 to %llu %llu\n", A2->row_id, A2->element);
      continue;
    } else if(A2->element > B2->element) {
      B2++;
 //     printf("\t\t\t\t\t\t\tmove B2 to %llu %llu\n", B2->row_id, B2->element);
      if(B1->element != B2->element) {
      	B1 = B2;
//      	printf("\t\t\t\t\t\t\tmove B1 to %llu %llu\n", B1->row_id, B1->element);
      }
      continue;
    }
    if(A2->element == B2->element) {
      printf("%d:A (%llu %llu) ",i, A2->row_id, A2->element); 
      printf("B (%llu %llu)\n", B2->row_id, B2->element);
    }
    B2++;
    if(B1->element != B2->element) {
      cntA++;
//      printf("cntA = %d ", cntA);
      if(cntA == A->num_of_tuples)
        break;
      A2++;
//      printf("move A2 to %llu %llu\n", A2->row_id, A2->element);
      if(A1->element != A2->element) {
        B1 = B2;
        A1 = A2;
      } else {
        B2 = B1;
      }
    }
//    printf("\t\t\t\t\t\t\tmove B2 to %llu %llu\n", B2->row_id, B2->element);
  i++;
  }
}

int main(int argc,char** argv){
  RelationPtr Relation_1,Relation_2;
  Arg_Manager_Ptr Manager = Create_ArgManager(argc, argv);
  Initialize(Manager, &Relation_1, &Relation_2);

  
  Sort(Relation_1);
  Sort(Relation_2);

//  Print_Relation(Relation_1);
  Print_Relation(Relation_2);

  //join
  join(Relation_1, Relation_2);

  Delete_ArgManager(Manager);
  Delete_Relation(Relation_1);
  Delete_Relation(Relation_2);

  return 0;
}
