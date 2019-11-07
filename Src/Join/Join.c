#include <stdlib.h>
#include "Join.h"
#include "../Initializer/Relation_Creator/Relation_Creator.h"

struct List_node{
  uint64_t Array[LIST_SIZE][2];
  int counter;
  Node_Ptr next;
};

struct Result_List{
  Node_Ptr start;
  Node_Ptr last;
};

void Print_List(Node_Ptr Pnode, int j, FILE *fp){
  for(int i = 0; i < LIST_SIZE;i++){
    if(Pnode->Array[i][1] == 0)
		continue;
    fprintf(fp, "%d: Table1: %llu, Table2: %llu\n", j, Pnode->Array[i][0], Pnode->Array[i][1]);
	j++;
  }
  if(Pnode->next)
	  Print_List(Pnode->next, j, fp);
//  printf("\n\n");
}


Node_Ptr New_Node() {
  Node_Ptr Pnode = (Node_Ptr)malloc(sizeof(struct List_node));
  Pnode->counter = 0;
  Pnode->next = NULL;
  return Pnode;
}

static List_Ptr Create_and_Initialize_List() {
  List_Ptr List = (List_Ptr)malloc(sizeof(struct Result_List));
  List->start = New_Node();
  List->last = List->start;
  return List;
}

void Insert_Record(List_Ptr List, uint64_t id_1, uint64_t id_2) {
//  Node_Ptr Pnode = List->start;
  Node_Ptr Pnode = List->last;
//  while(Pnode->next)
//	  Pnode = Pnode->next;

  if(Pnode->counter == LIST_SIZE) {
    Pnode->next = New_Node();
	Pnode = Pnode->next;
  }
  List->last = Pnode;

  Pnode->Array[Pnode->counter][0] = id_1;
  Pnode->Array[Pnode->counter][1] = id_2;

  Pnode->counter++; 
}

void Delete_List(List_Ptr List){
  Node_Ptr Pnode = List->start;
  Node_Ptr temp = Pnode;
  while(Pnode) {
	  temp = temp->next;
	  free(Pnode);
	  Pnode = temp;
  }
  free(List);
}

void Join(RelationPtr A, RelationPtr B) {
  printf("JOIN\n\n");
  List_Ptr List = Create_and_Initialize_List();

  Tuple_Ptr A1, A2, B1, B2;
  A1 = A2 = A->tuples;
  B1 = B2 = B->tuples;
  
  int i = 0;
  int cntA = 0;
  int cntB = 0;
//  FILE *fp = fopen("../../../Desktop/output.txt", "w");
  while(1) {
    if(A2->element < B2->element) {
      cntA++;
      if(cntA == A->num_of_tuples)
      	break;
      A2++;
      A1 = A2;
      continue;
    } else if(A2->element > B2->element) {
      B2++;
      if(B1->element != B2->element) {
      	B1 = B2;
      }
      continue;
    }
    if(A2->element == B2->element) {
      Insert_Record(List, A2->row_id, B2->row_id);
//    fprintf(fp, "%d: Table1: %llu, Table2: %llu\n", i, A2->row_id, B2->row_id);
      i++;
//      printf("%d:A (%llu %llu) ",i, A2->row_id, A2->element); 
//      printf("B (%llu %llu)\n", B2->row_id, B2->element);
    }
    B2++;
    if(B1->element != B2->element) {
      cntA++;
      if(cntA == A->num_of_tuples)
        break;
      A2++;
      if(A1->element != A2->element) {
        B1 = B2;
        A1 = A2;
      } else {
        B2 = B1;
      }
    }
  }
  printf("JOIN\n\n");
  FILE *fp = fopen("../../../Desktop/output.txt", "w");
  Print_List(List->start, 0, fp);
  fclose(fp);
  Delete_List(List);

//  Node_Ptr Pnode = List->start;
//  printf("Array = %lu\n", sizeof(uint64_t) * LIST_SIZE * 2);

//  printf("Array = %lu\n", sizeof(Pnode->Array));
//  printf("counter = %lu\n", sizeof(Pnode->counter));
//  printf("next = %lu\n", sizeof(Pnode->next));
//  printf("List Node = %lu\n", sizeof(struct List_node));
//  printf("Limit = %d\n", 1024 * 1024);
}
