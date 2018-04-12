test:
	@gcc -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	@bin/testhelloworld

build:
	@gcc -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.

all:		
	@gcc -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.
	@gcc -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.	
