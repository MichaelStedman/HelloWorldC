CC=gcc

test:
	@$(CC) -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	@bin/testhelloworld

build:
	@$(CC) -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.

all:		
	@$(CC) -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.
	@$(CC) -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.	
	

travistest:
	$(CC) -g -lrt -lm tests/testhelloworld.c src/library.c -I.
	testhelloworld

travisbuild:
	$(CC) -g -lrt -lm src/helloworld.c src/library.c -I.

	
