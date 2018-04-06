CC=clang
BUILD=build

all: build $(BUILD)/count-cpu $(BUILD)/get-cpu-speed $(BUILD)/get-boottime $(BUILD)/get-hostname

clean:
	rm -rf $(BUILD)

build:
	mkdir $(BUILD)

$(BUILD)/count-cpu:
	$(CC) count-cpu.c -o $(BUILD)/count-cpu

$(BUILD)/get-cpu-speed:
	$(CC) get-cpu-speed.c -o $(BUILD)/get-cpu-speed

$(BUILD)/get-boottime:
	$(CC) get-boottime.c -o $(BUILD)/get-boottime

$(BUILD)/get-hostname:
	$(CC) get-hostname.c -o $(BUILD)/get-hostname
