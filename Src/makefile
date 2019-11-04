CC = gcc
CFLAGS  = -g -Wall

main: main.o Initializer/Argument_Manager.o Initializer/Relations_Initializer.o Initializer/Arguments_Data.o Initializer/Relation_Creator/Relation_Creator.o Util/Utilities.o Histogram/Histogram.o Prefix_Sum/Prefix_Sum.o Relation_Sorting/Relation_Sorting.o
	$(CC) $(CFLAGS) -o main main.o Argument_Manager.o Relations_Initializer.o Arguments_Data.o Relation_Creator.o Utilities.o Histogram.o Prefix_Sum.o Relation_Sorting.o

main.o: main.c Initializer/Argument_Manager.h Initializer/Arguments_Data.h Initializer/Relations_Initializer.h Initializer/Relation_Creator Util/Utilities.h Histogram/Histogram.h Prefix_sum/Prefix_Sum.h Relation_Sorting/Relation_Sorting.h
	$(CC) -c main.c 

Relation_Sorting/Relation_Sorting.o: Relation_Sorting/Relation_Sorting.c Relation_Sorting/Relation_Sorting.h
	$(CC) -c Relation_Sorting/Relation_Sorting.c


Initializer/Relation_Creator/Relation_Creator.o: Initializer/Relation_Creator/Relation_Creator.c Initializer/Relation_Creator/Relation_Creator.h
	$(CC) -c Initializer/Relation_Creator/Relation_Creator.c 

Prefix_Sum/Prefix_Sum.o: Prefix_sum/Prefix_Sum.c Prefix_sum/Prefix_Sum.h Initializer/Relation_Creator
	$(CC) -c Prefix_Sum/Prefix_Sum.c 
	
Histogram/Histogram.o: Histogram/Histogram.c Histogram/Histogram.h Initializer/Relation_Creator
	$(CC) -c Histogram/Histogram.c 
	
Util/Utilities.o: Util/Utilities.c Util/Utilities.h
	$(CC) -c Util/Utilities.c


Initializer/Relations_Initializer.o: Initializer/Relations_Initializer.c Initializer/Relations_Initializer.h
	$(CC) -c Initializer/Relations_Initializer.c 

Initializer/Arguments_Data.o: Initializer/Arguments_Data.c Initializer/Arguments_Data.h
	$(CC) -c Initializer/Arguments_Data.c 

Initializer/Argument_Manager.o: Initializer/Argument_Manager.c Initializer/Argument_Manager.h
	$(CC) -c Initializer/Argument_Manager.c 
	
clean:
	$(RM) main *.o 
