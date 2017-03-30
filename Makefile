####################
# --- Makefile --- #
#   -   Root   -   #
####################

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

default: all

FRONTEND = front_end
MIDDLEEND = middle_end_modif
DEPS_FRONTEND = $(shell ls $(FRONTEND)/*)
DEPS_MIDDLEEND = $(shell ls $(MIDDLEEND)/*)
CFLAGS = -std=c++11 -DYYDEBUG

all: comp

comp: $(DEPS_FRONTEND) comp.l comp.y main.cpp $(DEPS_MIDDLEEND)
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	make -C $(FRONTEND)
	make -C $(MIDDLEEND)
	g++ $(CFLAGS) -o main.o -c main.cpp
	g++ $(CFLAGS) -o comp *.c *.cpp $(FRONTEND)/*.o $(MIDDLEEND)/*.o

clean:
	make -C $(FRONTEND) clean
	make -C $(MIDDLEEND) clean
	rm -f comp comp.tab.c comp.tab.h comp.output lex.yy.c
