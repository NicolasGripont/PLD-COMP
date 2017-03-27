####################
# --- Makefile --- #
####################

# --- Add header files here:
INT = Declaration.h Genesis.h DeclarationVariable.h Type.h MultipleDeclarationVariable.h ArgumentList.h Argument.h Expression.h DeclarationInitVariable.h DeclarationArrayVariable.h GlobalDeclarationVariable.h FunctionCallExpression.h BinaryOperatorExpression.h UnaryOperatorExpression.h ExpressionInteger.h ExpressionVariable.h CrementVariable.h DeclarationFunctionStatement.h Return.h SimpleStatement.h MultipleStatement.h Statement.h IterationStatement.h LoopExpression.h WhileLoop.h ForLoop.h DeclarationFunction.h

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
GlobalDeclarationVariable.o: GlobalDeclarationVariable.copp Declaration.h MultipleDeclarationVariable.h
FunctionCallExpression.o: FunctionCallExpression.cpp  Expression.h
BinaryOperatorExpression.o: BinaryOperatorExpression.cpp Expression.h
UnaryOperatorExpression.o: UnaryOperatorExpression.cpp Expression.h
ExpressionInteger.o: ExpressionInteger.cpp Expression.h
ExpressionVariable.o: ExpressionVariable.cpp Expression.h
CrementVariable.o: CrementVariable.cpp ExpressionVariable.h Expression.h
DeclarationFunctionStatement.o: DeclarationFunctionStatement.cpp
Return.o: Return.cpp Expression.h
SimpleStatement.o: SimpleStatement.cpp
MultipleStatement.o: MultipleStatement.cpp SimpleStatement.h
Statement.o: Statement.cpp MultipleStatement.h
IterationStatement.o: IterationStatement.cpp SimpleStatement.h Statement.h
LoopExpression.o: LoopExpression.cpp Expression.h
WhileLoop.o: WhileLoop.cpp IterationStatement.h Expression.h
ForLoop.o: ForLoop.cpp IterationStatement.h LoopExpression.h
DeclarationFunction.o: DeclarationFunction.cpp Declaration.h DeclarationFunctionStatement.h ArgumentList.h Type.h

clean:
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(BUILDIR)*.o
