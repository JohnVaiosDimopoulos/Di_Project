CC = gcc
CFLAGS  = -g -Wall

main: main.o Initializer/Argument_Manager.o Initializer/Table_Initializer.o Initializer/Arguments_Data.o Initializer/Relation_Creator Util/Utilities.o Histogram/Histogram.o Pre_Processing/Pre_Processor.o Histogram/Prefix_Sum.o
	$(CC) $(CFLAGS) -o main main.o Argument_Manager.o Table_Initializer.o Arguments_Data.o Data_Table.o Utilities.o Histogram.o Pre_Processor.o Prefix_Sum.o

main.o: main.c Initializer/Argument_Manager.h Initializer/Arguments_Data.h Initializer/Relations_Initializer.h Initializer/Relation_Creator Util/Utilities.h Histogram/Histogram.h Prefix_sum/Prefix_Sum.h
	$(CC) -c main.c 

Pre_Processing/Pre_Processor.o: Pre_Processing/Pre_Processor.c Pre_Processing/Pre_Processor.h
	$(CC) -c Pre_Processing/Pre_Processor.c 

Histogram/Prefix_Sum.o: Prefix_sum/Prefix_Sum.c Prefix_sum/Prefix_Sum.h Initializer/Relation_Creator
	$(CC) -c Histogram/Prefix_Sum.c 
	
Histogram/Histogram.o: Histogram/Histogram.c Histogram/Histogram.h Initializer/Relation_Creator
	$(CC) -c Histogram/Histogram.c 
	
Util/Utilities.o: Util/Utilities.c Util/Utilities.h
	$(CC) -c Util/Utilities.c

Initializer/Data_Table/Data_Table.o: Initializer/Relation_Creator Initializer/Relation_Creator
	$(CC) -c Initializer/Data_Table/Data_Table.c 
	
Initializer/Table_Initializer.o: Initializer/Relations_Initializer.c Initializer/Relations_Initializer.h
	$(CC) -c Initializer/Table_Initializer.c 

Initializer/Arguments_Data.o: Initializer/Arguments_Data.c Initializer/Arguments_Data.h
	$(CC) -c Initializer/Arguments_Data.c 

Initializer/Argument_Manager.o: Initializer/Argument_Manager.c Initializer/Argument_Manager.h
	$(CC) -c Initializer/Argument_Manager.c 
	
clean:
	$(RM) main *.o 
