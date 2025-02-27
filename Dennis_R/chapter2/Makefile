# Compiler and Flags
CC = gcc
CFLAGS = -w
LDFLAGS =
 
# Debug or Release configuration
DEBUG = 1
 
# Chapters
#CHAPTERS = chapter1
CHAPTERS = chapter2
#CHAPTERS = chapter3
#CHAPTERS = chapter4
#CHAPTERS = chapter5
 
# Executable name (debug or release)
ifeq ($(DEBUG), 1)
    CFLAGS += -g -O0
    EXECUTABLE_NAME = main_binary_file
endif
 
# Targets
.PHONY: all $(CHAPTERS) build compile execute clean
 
all: $(CHAPTERS)
 
# Build each chapter
$(CHAPTERS):
	echo "Building $(CHAPTERS)..."

	@$(MAKE) build CHAPTER=$@
	@$(MAKE) execute CHAPTER=$@
 
# Create build and execute directories
build:
	@mkdir -p $(CHAPTER)/build
	@mkdir -p $(CHAPTER)/execute
	@$(MAKE) compile CHAPTER=$(CHAPTER)
	@$(CC) $(CFLAGS) -I $(CHAPTER)/header $(CHAPTER)/build/*.o $(LDFLAGS) -o $(CHAPTER)/execute/$(EXECUTABLE_NAME)
 
# Compile each function .c file into an object (.o) file
compile:
	@mkdir -p $(CHAPTER)/build
	@for src in $(wildcard $(CHAPTER)/function/*.c); do \
		$(CC) $(CFLAGS) -I $(CHAPTER)/header -c $$src -o $(CHAPTER)/build/$$(basename $$src .c).o; \
	done
	@$(CC) $(CFLAGS) -I $(CHAPTER)/header -c $(CHAPTER)/main/main.c -o $(CHAPTER)/build/main.o
 
# Run the program from the execute directory
execute:
	@echo "Running $(CHAPTER)/execute/$(EXECUTABLE_NAME)..."
	@./$(CHAPTER)/execute/$(EXECUTABLE_NAME)
 
# Clean up build and execute files for all chapters
clean:
	@rm -rf $(CHAPTERS:%=%/build/*) $(CHAPTERS:%=%/execute/*)
