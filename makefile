test:
	@gcc -o bin/testhelloworld tests/testhelloworld.c src/library.c -I.
	@bin/testhelloworld

build:
	@gcc -o bin/helloworld src/helloworld.c src/library.c -I.	