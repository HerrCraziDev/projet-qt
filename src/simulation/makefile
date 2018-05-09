CFLAGS = -Wall -pedantic -std=c++14

SRC = $(wildcard *.cpp)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addsuffix .o, $(NOM))

all: term

remake: clean all

term : $(OBJ)
	g++ *.o -o $@ 

%.o: %.cpp
	g++ -c $< -o $@ $(CFLAGS)

clean:
	rm *.o *.out *.gch -f

clear:
	rm *.o *.gch -f