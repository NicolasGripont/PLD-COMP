####################
# --- Makefile --- #
#   -   Root   -   #
####################

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

default: all

FRONTEND = structure
DEPS = $(shell ls $(FRONTEND)/*)
CFLAGS = -std=c++11 -DYYDEBUG

all: comp

comp: $(DEPS) comp.l comp.y
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	make -C $(FRONTEND)
	g++ $(CFLAGS) -o comp *.c $(FRONTEND)/*.o

clean:
	make -C $(FRONTEND) clean
	rm -f comp comp.tab.c comp.tab.h comp.output lex.yy.c