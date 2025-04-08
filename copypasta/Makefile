target: build   execute clean
EXE_NAME = why
CC = gcc
file1=fun7_7.c
#file2=
file1_o=$(file1:.c=.o)
#file2_o=$(file2:.c=.o)

build:  $(file1_o)  
	
	$(CC) -g $(file1_o)  -o $(EXE_NAME)

$(file1_o):
	$(CC)  -c $(file1)

#$(file2_o).o:
#       $(CC) -w -c $(file2)

execute:
	./$(EXE_NAME)

clean:
	rm -f *.o
	rm -f $(EXE_NAME)
#%.o:   %.c
#       $(CC) -c $< -o $@
