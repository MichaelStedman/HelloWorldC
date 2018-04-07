test:
	@gcc -g -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	@bin/testhelloworld

build:
	@gcc -g -o bin/helloworld src/helloworld.c src/library.c -I.	
