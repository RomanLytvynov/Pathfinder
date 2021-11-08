.PHONY: all libmx uninstall clean reinstall

all: libmx

libmx:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c src/*.c
	mkdir obj
	mv *.o obj
	ar -rsc libmx.a obj/*.o

clean:
	rm -rdf obj
	rm -rf *.o

uninstall: clean
	rm -rf libmx.a

reinstall:
	make uninstall
	make
