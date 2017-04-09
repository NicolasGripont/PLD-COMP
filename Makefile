####################
# --- Makefile --- #
#   -   Root   -   #
####################

MAKEFLAGS += --no-builtin-rules
.SUFFIXES:

default: all

FRONTEND = front_end
MIDDLEEND = middle_end
BACKEND = back_end
TEST = tests

DEPS_FRONTEND = $(shell ls $(FRONTEND)/*.h $(FRONTEND)/*.cpp)
DEPS_MIDDLEEND = $(shell ls $(MIDDLEEND)/*.h $(MIDDLEEND)/*.cpp)
DEPS_BACKEND = $(shell ls $(BACKEND)/*.h $(BACKEND)/*.cpp)
LIST_TEST = $(shell ls -d $(TEST)/*/)

CFLAGS = -g3 -std=c++11 -DYYDEBUG

all: comp

comp: $(DEPS_FRONTEND) comp.l comp.y main.cpp $(DEPS_MIDDLEEND) $(DEPS_BACKEND)
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	make -C $(FRONTEND)
	make -C $(MIDDLEEND)
	make -C $(BACKEND)
	g++ $(CFLAGS) -o main.o -c main.cpp
	g++ $(CFLAGS) -o comp *.c *.cpp $(FRONTEND)/*.o $(MIDDLEEND)/*.o $(BACKEND)/*.o

clean:
	make -C $(FRONTEND) clean
	make -C $(MIDDLEEND) clean
	make -C $(BACKEND) clean
	rm -f comp comp.tab.c comp.tab.h comp.output lex.yy.c

test: comp
	$(foreach var, $(LIST_TEST), ./$(TEST)/scriptTestAuto.sh ./comp ./$(var);)
