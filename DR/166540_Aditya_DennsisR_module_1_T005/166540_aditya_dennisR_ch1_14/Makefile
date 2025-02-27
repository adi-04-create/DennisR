traget: build execute clean
build: ex_14_main.o
		gcc ex_14_main.o -o a
execute:
		./a
clean:
		rm -rf a
		rm -rf *.o
%.o : %.c
		gcc -c $< -o $@

