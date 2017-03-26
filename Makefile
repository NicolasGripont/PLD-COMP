#VARIABLES
MAKEFILE = makefile
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = declaration.h genesis.h declarationvariable.h declarationfunction.h multipledeclarationvariableglobal.h multipleargument.h argument.h statement.h multiplestatement.h multipledeclarationvariablelocal.h declarationinitvariable.h expression.h declarationarrayvariable.h binaryoperatorexpression.h return.h iterationstatement.h whileloop.h forloop.h selectionstatement.h ifelsestatement.h unaryoperatorexpression.h expressioninteger.h expressionvariable.h expressionarrayvariable.h assignmentexpression.h type.h globaldeclarationvariable.h assignmentvariable.h assignmentoperationvariable.h
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

genesis.o: declaration.h
declarationvariable.o: type.h
declarationfunction.o: declaration.h type.h multipleargument.h
multipledeclarationvariableglobal.o: declarationvariable.h declaration.h
multipleargument.o: argument.h
multiplestatement.o: statement.h
multipledeclarationvariablelocal.o: statement.h declarationvariable.h
declarationinitvariable.o: declarationvariable.h expression.h
declarationarrayvariable.o: declarationvariable.h
binaryoperatorexpression.o: expression.h
unaryoperatorexpression.o: expression.h
return.o: expression.h statement.h
iterationstatement.o: statement.h multiplestatement.h 
whileloop.o: iterationstatement.h expression.h
forloop.p: iterationstatement.h expression.h
selectionstatement.o: statement.h expression.h multiplestatement.h
ifelsestatement.o: selectionstatement.h multiplestatement.h
expression.o: statement.h
expressioninteger.o: expression.h
expressionvariable.o: expression.h
expressionarrayvariable.o: expressionvariable.h expression.h
assignmentexpression.o: expressionvariable.h expression.h
type.o: 
globaldeclarationvariable.o: multipledeclarationvariablelocal.h declaration.h
assignmentvariable.o: expressionvariable.h expression.h
assignmentoperationvariable.o: assignmentvariable.h

$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(OBJ)
