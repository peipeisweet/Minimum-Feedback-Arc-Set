.PHONY: all clean
all: bin/cb

bin/cb:
	@mkdir -p bin
	g++ -O3 -std=c++11 src/main.cpp -o bin/cb

clean:
	rm -rf bin/