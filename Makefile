CFLAGS=-Wall -g

#${p}: project/lesson name

default: run

clean:
	rm -rf ${p}/bin

build:
	mkdir -p ${p}/bin
	gcc ${p}/${p}.c -o ${p}/bin/${p}

run: build
	${p}/bin/${p} ${ARGV}