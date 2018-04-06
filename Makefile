CC=clang
BUILD=build

all: build $(BUILD)/count-cpu $(BUILD)/get-cpu-speed

clean:
	rm -rf $(BUILD)

build:
	mkdir $(BUILD)

build/count-cpu:
	$(CC) count-cpu.c -o $(BUILD)/count-cpu

build/get-cpu-speed:
	$(CC) get-cpu-speed.c -o $(BUILD)/get-cpu-speed
