target: build execute clean
DEBUG = 1
EXECUTABLE_NAME = ex
CC = gcc
CFLAGS = -w

ifeq ($(DEBUG), 1)
                CFLAGS += -g -O0
else
                CFLAGS += -g -O3
endif

COMPILER_CALL = $(CC) $(CFLAGS)

build: func_3_2.o main_3_2.o
		$(COMPILER_CALL) func_3_2.o main_3_2.o -o $(EXECUTABLE_NAME)

#hadder.o:
#                $(COMPILER_CALL) -c hadder.c

#main.o:
#                $(COMPILER_CALL) -c main.c
execute:
		./$(EXECUTABLE_NAME)

clean:
		rm -rf *.o
		rm -rf $(EXECUTABLE_NAME)

%.o : %.c
		$(COMPILER_CALL) -c $< -o $@
