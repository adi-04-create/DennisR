target: build execute clean
DEBUG = 0
EXECUTABLE_NAME = file
CC = gcc
CFLAGS = -Wall -I ~/C_Programming/Dennis_R/ 
CH = 1
NO = 5
 
ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif
 
COMPILER_CALL = $(CC) $(CFLAGS)
 

SRC_FILES = ~/C_Programming/Dennis_R/166540_Aditya_DennsisR_module_$(CH)_T005/166540_aditya_dennisR_ch$(CH)_$(NO)/func_$(CH)_$(NO).c
OBJ_FILES = $(SRC_FILES:.c=.o)
 
MAIN = main.c

MAIN_O = $(MAIN:.c=.o)

build: $(OBJ_FILES) $(MAIN_O)
	$(COMPILER_CALL) $(OBJ_FILES) $(MAIN_O) -o $(EXECUTABLE_NAME)
 
%.o : %.c
	$(COMPILER_CALL) -c $< -o $@
 
execute:
	./$(EXECUTABLE_NAME)
 
clean:
	rm -f $(OBJ_FILES)
	rm -f $(MAIN_O)
	rm -f $(EXECUTABLE_NAME)
