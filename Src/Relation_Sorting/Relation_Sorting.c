#include "Relation_Sorting.h"



/*Sort(RelationPtr Relation){
 * Allocate R'=same size as Relation
 * Sort_Relation(Relation,R',1)
 * }
 *
 *
 * */

/*Sort_Relation(RelationPtr Relation,Relation_Ptr Relation', int byte)
 *  * Histogram_Prt Histogram = Get_Histogram(Relation,byte);
 * Psum_Ptr Psum = Get_Psum(Histogram);
 * Sort R based on given byte to R'
 * memcpy(R->array,R'->array,array_size)
 *
 *
 * (for each bucket)
 * for(int i =0;i<Psum->num_of_elements;i++){
 * New_Relation = Create_Relation_with_given_array(
 * (size)Histogram->Array[i].quantity,(bicket_start)Relation->Array[Psum->Array[i].sum]);
 * Sort_Relation(New_Relation,Relation',byte-1);
 * New_Relation->Array=NULL;
 * Delete(New_Relation);
 * }
 * Delete(Psum);
 * Delete(Histogram);
 *
 *
 *
 *
 *
 *
 *
 * */
