trget: build execute clean 

CC = gcc

# INPUT FILES
file1 = hello.c
file2 = here.c
file3 = bye.c
main = main.c

# CONVERTING .C TO .O (OBJECT FILES)
file1_o = $(file1:.c=.o)
file2_o = $(file2:.c=.o)
file3_o = $(file3:.c=.o)
main_o = $(main:.c=.o)

# CALLING A LIBRARY NAME
lib = mylib.a

# LINKING MAIN FILE WITH LIBRARY FILE AND CREATING A BINARY
build: static $(main_o)
	$(CC) $(main_o) -o output -L . $(lib)

# CREATING A LIBRARY FILE
static: $(file1_o) $(file2_o) $(file3_o)
	ar rs $(lib) $(file1_o) $(file2_o) $(file3_o)

# CREATING OBJECT FILES
%.o: %.c
	$(CC) -c -g -Wall $<

# EXECUTING THE BINARY
execute:
	./output

# REMOVING ALL OBJECT FILES AND A BINARY FILE
clean:
	rm -rf $(file1_o) $(file2_o) $(file3_o) $(main_o) output


