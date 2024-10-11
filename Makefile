all: build
build:
	g++ main.cpp -o main -Wall -g
run:
	./main