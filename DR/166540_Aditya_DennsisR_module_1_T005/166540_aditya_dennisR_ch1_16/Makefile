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

build: main_1_16.o func_1_16.o
		$(COMPILER_CALL)  main_1_16.o  func_1_16.o -o $(EXECUTABLE_NAME)

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
