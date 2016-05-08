CFLAG = -c -std=c++11 -g -fmax-errors=3 -lpthread
CC = g++
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, %.o, $(SRC))

all : $(OBJ)
	$(CC) -o test $(OBJ) -lpthread

%.o : %.cc %.h
	$(CC) $< $(CFLAG)

clean:
	rm $(OBJ)
