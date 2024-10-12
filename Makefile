all: build
build:
	g++ main.cpp -o main -Wall -g
run:
	./main
win:
	x86_64-w64-mingw32-g++ main.cpp -o main.exe -Wall
clean:
	rm main passdb.txt && touch passdb.txt && rm main.exe