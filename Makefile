# Compiler and options
CC     = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
LDLIBS = -lm

HEADERS = include/particles.h include/pusher.h
TESTS   = build/test_pusher_uniform build/test_pusher_harmonic

# Default target: build both tests
all: $(TESTS)

# Pusher module, compiled once and reused by both tests
build/pusher.o: src/pusher.c $(HEADERS)
	mkdir -p build
	$(CC) $(CFLAGS) -c src/pusher.c -o build/pusher.o

# Test executables: test source + pusher module
build/test_pusher_uniform: tests/test_pusher_uniform.c build/pusher.o $(HEADERS)
	$(CC) $(CFLAGS) tests/test_pusher_uniform.c build/pusher.o -o build/test_pusher_uniform $(LDLIBS)

build/test_pusher_harmonic: tests/test_pusher_harmonic.c build/pusher.o $(HEADERS)
	$(CC) $(CFLAGS) tests/test_pusher_harmonic.c build/pusher.o -o build/test_pusher_harmonic $(LDLIBS)

# Run both tests and save their output
test: $(TESTS)
	mkdir -p output
	./build/test_pusher_uniform > output/uniform.txt
	./build/test_pusher_harmonic > output/harmonic.txt

# Build the figures from the outputs
figures: test
	python3 scripts/plot_uniform.py
	python3 scripts/plot_harmonic.py

# Remove everything that can be regenerated
clean:
	rm -rf build output

.PHONY: all test figures clean