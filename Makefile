all: clean compile run
	
compile:
	g++ -std=c++20 -Wall -Wextra card.cpp carddeck.cpp player.cpp main.cpp game.cpp -o main

run:
	./main

docs:
	doxygen Doxyfile

clean:
	rm -rf main
