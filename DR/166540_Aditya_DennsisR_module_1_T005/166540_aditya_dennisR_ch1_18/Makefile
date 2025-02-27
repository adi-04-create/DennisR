traget: build execute clean
build: ex_18_main.o
		gcc ex_18_main.o -o a
execute:
		./a
clean:
		rm -rf *.o
		rm -rf a
%.o : %.c
		gcc -c $< -o $@

