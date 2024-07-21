
SOURCES = main.c printer.c options.c io.c util.c

build:
	rm -rf bin && mkdir bin
	cd src && gcc -std=c17 -Wall -Werror -I../include -o ../bin/hexdump ${SOURCES} -lm

test:
	bin/hexdump testdata/sonnet18.txt

clean:
	rm -rf bin
