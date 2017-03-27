############
# Makefile #
############

# --- Add header file here:
INT = Declaration.h Genesis.h

BUILDIR = structure/
OBJ = $(addprefix $(BUILDIR), $(INT:.h=.o))
COMP = g++
FLAGS = -std=c++11 -DYYDEBUG

default: $(OBJ)
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	$(COMP) $(FLAGS) -o comp *.c $(OBJ)

%.o: %.cpp
	$(COMP) -o $@ -c $< $(FLAGS)

# --- Add requirements here:
Declaration.o: Declaration.cpp
Genesis.o: Genesis.cpp Declaration.h

clean:
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(BUILDIR)*.o
