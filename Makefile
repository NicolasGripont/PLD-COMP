####################
# --- Makefile --- #
####################

# --- Add header files here:
INT = Declaration.h Genesis.h DeclarationVariable.h Type.h MultipleDeclarationVariable.h ArgumentList.h Argument.h Expression.h DeclarationInitVariable.h DeclarationArrayVariable.h GlobalDeclarationVariable.h

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

# --- Add requirement files here:
Declaration.o: Declaration.cpp
Genesis.o: Genesis.cpp Declaration.h
DeclarationVariable.o: DeclarationVariable.cpp
Type.o: Type.cpp
MultipleDeclarationVariable.o: MultipleDeclarationVariable.cpp Type.h
Argument.o: Argument.cpp Type.h
ArgumentList.o: ArgumentList.cpp Argument.h
Expression.o: Expression.cpp
DeclarationInitVariable.o: DeclarationInitVariable.cpp Expression.h DeclarationVariable.h
DeclarationArrayVariable.o: DeclarationArrayVariable.cpp DeclarationVariable.h
GlobalDeclarationVariable.o : GlobalDeclarationVariable.copp Declaration.h MultipleDeclarationVariable.h

clean:
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(BUILDIR)*.o
