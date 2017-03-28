####################
# --- Makefile --- #
#   -   Root   -   #
####################

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

default: comp

FRONTEND = structure
DEPS = $(shell ls $(FRONTEND)/*)
COMP = g++
FLAGS = -std=c++11 -DYYDEBUG

all: comp

comp: $(DEPS)
	make -C $(FRONTEND)
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	g++ $(FLAGS) -o comp *.c $(FRONTEND)/*.o

clean:
	rm -f comp comp.tab.c comp.tab.h comp.output lex.yy.c $(FRONTEND)/*.o $(FRONTEND)/*.d