####################
# --- Makefile --- #
#   -   Root   -   #
####################

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

default: all

FRONTEND = front_end
DEPS = $(shell ls $(FRONTEND)/*)
CFLAGS = -std=c++11 -DYYDEBUG

all: comp

comp: $(DEPS) comp.l comp.y main.cpp
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	make -C $(FRONTEND)
	g++ $(CFLAGS) -o main.o -c main.cpp
	g++ $(CFLAGS) -o comp *.c *.cpp $(FRONTEND)/*.o

clean:
	make -C $(FRONTEND) clean
	rm -f comp comp.tab.c comp.tab.h comp.output lex.yy.c