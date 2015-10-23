CFLAGS=-Wall -g

#${p}: project/lesson name

default: run

clean:
	rm ${p}/${p}

build:
	gcc ${p}/${p}.c -o ${p}/${p}

run: build
	./${p}/${p}