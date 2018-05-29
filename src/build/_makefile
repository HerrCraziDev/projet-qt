CFLAGS = -Wall -pedantic -std=c++14
LDFLAGS = -lpthread

SRC = $(wildcard *.cpp)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addsuffix .o, $(NOM))
TARGET = term

all: term

remake: clean all

run: all 
	./$(TARGET)

term : $(OBJ)
	g++ *.o -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	g++ -c $< -o $@ $(CFLAGS)

clean:
	rm *.o *.out *.gch -f

clear:
	rm *.o *.gch -f
