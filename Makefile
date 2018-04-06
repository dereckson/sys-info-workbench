CC=clang

all: count-cpu

clean:
	rm -f count-cpu

count-cpu:
	$(CC) count-cpu.c -o count-cpu
