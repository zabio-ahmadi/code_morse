morse: main.o morse.o 
	gcc -g -Wall -Wextra main.o morse.o -o morse -fsanitize=address -fsanitize=leak 

morse.o: morse.h morse.c
	gcc -g -Wall -Wextra -c morse.c -o morse.o -fsanitize=address -fsanitize=leak 

main.o: main.c 
	gcc -g -Wall -Wextra -c main.c -o main.o -fsanitize=address -fsanitize=leak 


run : 
	./morse

clean : 
	rm -rf *.o morse

rebuild: clean morse