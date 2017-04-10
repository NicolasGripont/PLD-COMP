####################
# --- Makefile --- #
#   - FrontEnd -   #
####################

default: all

SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
CFLAGS = -g3 -std=c++11 -DYYDEBUG

all: $(OBJ)

-include $(SRC:.cpp=.d)

%.o: %.cpp
	g++ -o $@ $(CFLAGS) -c $< 
	g++ -MM -MT $@ $(CFLAGS) $< > $*.d

clean:
	rm -f *.o *.d
