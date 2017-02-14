all: peg_solitaire.cpp
	g++ -Wall -o a.out peg_solitaire.cpp

clean:
	$(RM) a.out