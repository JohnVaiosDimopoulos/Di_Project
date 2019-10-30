CC = gcc
CFLAGS  = -g -Wall

main: main.o Initializer/Argument_Manager.o Initializer/Table_Files.o Initializer/Table_Initializer.o Initializer/Data_Table/Data_Table.o Util/Utilities.o Initializer/Histogram/Histogram.o 
	$(CC) $(CFLAGS) -o main main.o Argument_Manager.o Table_Files.o Table_Initializer.o Data_Table.o Utilities.o Histogram.o

main.o: main.c Initializer/Argument_Manager.h Initializer/Table_Files.h Initializer/Table_Initializer.h Initializer/Data_Table/Data_Table.h Util/Utilities.h Initializer/Histogram/Histogram.h
	$(CC) -c main.c 

Initializer/Histogram/Histogram.o: Initializer/Histogram/Histogram.c Initializer/Data_Table/Data_Table.h Initializer/Histogram/Histogram.h
	$(CC) -c Initializer/Histogram/Histogram.c 
	
Util/Utilities.o: Util/Utilities.c Util/Utilities.h
	$(CC) -c Util/Utilities.c

Initializer/Data_Table/Data_Table.o: Initializer/Data_Table/Data_Table.c Initializer/Data_Table/Data_Table.h
	$(CC) -c Initializer/Data_Table/Data_Table.c 
	
Initializer/Table_Initializer.o: Initializer/Table_Initializer.c Initializer/Table_Initializer.h
	$(CC) -c Initializer/Table_Initializer.c 

Initializer/Table_Files.o: Initializer/Table_Files.c Initializer/Table_Files.h
	$(CC) -c Initializer/Table_Files.c 

Initializer/Argument_Manager.o: Initializer/Argument_Manager.c Initializer/Argument_Manager.h
	$(CC) -c Initializer/Argument_Manager.c 
	
clean:
	$(RM) main *.o 
