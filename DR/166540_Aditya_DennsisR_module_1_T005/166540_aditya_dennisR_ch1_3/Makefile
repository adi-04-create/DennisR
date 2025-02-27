target: build	execute	clean
EXE_NAME = why
CC = gcc 
file1=exe3.c
file2=fun3.c
file1_o={$(file1)%.c}
file2_o={$(file2)%.c}

build:	$(file1_o).o	$(file2_o).o 
	$(CC)  *.o -o $(EXE_NAME)

$(file1_o).o:
	$(CC) -w -c $(file1)

$(file2_o).o:
	$(CC) -w -c $(file2)

execute:
	./$(EXE_NAME)

clean:
	rm -f *.o
	rm -f $(EXE_NAME)
#%.o:	%.c
#	$(CC) -c $< -o $@
