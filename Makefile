#VARIABLES
MAKEFILE = makefile
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = declaration.h genesis.h declarationvariable.h declarationfunction.h multipledeclarationvariableglobal.h multipleargument.h argument.h statement.h multiplestatement.h multipledeclarationvariablelocal.h declarationinitvariable.h expression.h declarationarrayvariable.h binaryoperatorexpression.h return.h iterationstatement.h whileloop.h forloop.h selectionstatement.h ifelsestatement.h unaryoperatorexpression.h expressioninteger.h expressionvariable.h expressionarrayvariable.h assignmentexpression.h
REAL = $(INT:.h=.cpp)
OBJ = $(INT:.h=.o)
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = #-std=c++11 -Wall -O3
EDLFLAGS = 
LIBS = 
LIBPATH =# -L
INCPATH =# -I
CLEAN = clean
RESSOURCES = 

default: $(OBJ)
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	g++ -std=c++11 -DYYDEBUG -o comp *.c

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

genesis.o: declaration.h $(MAKEFILE)
declarationvariable.o: type.h $(MAKEFILE)
declarationfunction.o: declaration.h type.h multipleargument.h $(MAKEFILE)
multipledeclarationvariableglobal.o: declarationvariable.h declaration.h $(MAKEFILE)
multipleargument.o: argument.h $(MAKEFILE)
multiplestatement.o: statement.h $(MAKEFILE)
multipledeclarationvariablelocal.o: statement.h declarationvariable.h $(MAKEFILE)
declarationinitvariable.o: declarationvariable.h expression.h $(MAKEFILE)
declarationarrayvariable.o: declarationvariable.h $(MAKEFILE)
binaryoperatorexpression.o: expression.h $(MAKEFILE)
unaryoperatorexpression.o: expression.h $(MAKEFILE)
return.o: expression.h statement.h $(MAKEFILE)
iterationstatement.o: statement.h multiplestatement.h $(MAKEFILE)
whileloop.o: iterationstatement.h expression.h $(MAKEFILE)
forloop.p: iterationstatement.h expression.h $(MAKEFILE)
selectionstatement.o: statement.h expression.h multiplestatement.h $(MAKEFILE)
ifelsestatement.o: selectionstatement.h multiplestatement.h $(MAKEFILE)
expression.o: statement.h $(MAKEFILE)
expressioninteger.o: expression.h $(MAKEFILE)
expressionvariable.o: expression.h $(MAKEFILE)
expressionarrayvariable.o: expressionvariable.h expression.h $(MAKEFILE)
assignmentexpression.o: expressionvariable.h expression.h $(MAKEFILE)

$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(OBJ)
