CC=gcc

test:
	@$(CC) -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	@bin/testhelloworld

build:
	@$(CC) -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.

all:		
	@$(CC) -g -lrt -lm -o bin/helloworld src/helloworld.c src/library.c -I.
	@$(CC) -g -lrt -lm -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.

cov:		
	@$(CC) -g -lrt -lm -Wall -fprofile-arcs -ftest-coverage -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	lcov --directory . --zerocounters
	@bin/testhelloworld
	gcov testhelloworld
	gcov library
	lcov --directory . --capture --output-file coverage/app.info
	genhtml coverage/app.info -o ./coverage

travistest:
	$(CC) -g -lrt -lm -Wall -fprofile-arcs -ftest-coverage -o testhelloworld tests/testhelloworld.c src/library.c -I.
	./testhelloworld
	gcov testhelloworld
	gcov library

travisbuild:
	$(CC) -g -lrt -lm -Wall -fprofile-arcs -ftest-coverage -o helloworld src/helloworld.c src/library.c -I.
	./helloworld
	gcov helloworld	
