####################
# --- Makefile --- #
#   - FrontEnd -   #
####################

default: all

INT = $(shell ls *.h)
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++11 -DYYDEBUG

all: $(OBJ)

-include $(SRC:.cpp=.d)

%.o: %.cpp
	g++ -o $@ $(FLAGS) -c $< 
	g++ -MM -MT $@ $(FLAGS) $< > $*.d

clean:
	rm -f *.o *.d