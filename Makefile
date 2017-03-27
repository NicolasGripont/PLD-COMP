####################
# --- Makefile --- #
####################

# --- Add header files here:
INT = Printer.h Declaration.h Genesis.h DeclarationVariable.h Type.h MultipleDeclarationVariable.h ArgumentList.h \
Argument.h Expression.h DeclarationInitVariable.h DeclarationArrayVariable.h GlobalDeclarationVariable.h \
FunctionCallExpression.h BinaryOperatorExpression.h UnaryOperatorExpression.h ExpressionInteger.h \
ExpressionVariable.h CrementVariable.h DeclarationFunctionStatement.h DeclarationFunction.h \
ExpressionSimpleVariable.h ExpressionArrayVariable.h AssignmentVariable.h AssignmentOperationVariable.h \
Return.h SimpleStatement.h ReturnStatement.h UselessStatement.h MultipleStatement.h Statement.h \
InitFunctionStatement.h BlockDeclarationVariable.h IterationStatement.h SelectionStatement.h ExpressionStatement.h \
DeclarationVariableStatement.h PureDeclarationFunctionStatement.h LoopExpression.h WhileLoop.h ForLoop.h \

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
Printer.o: Printer.cpp
Declaration.o: Declaration.cpp Printer.h
Genesis.o: Genesis.cpp Declaration.h Printer.h
DeclarationVariable.o: DeclarationVariable.cpp Printer.h
Type.o: Type.cpp Printer.h
MultipleDeclarationVariable.o: MultipleDeclarationVariable.cpp Type.h Printer.h
Argument.o: Argument.cpp Type.h Printer.h
ArgumentList.o: ArgumentList.cpp Argument.h Printer.h
Expression.o: Expression.cpp Printer.h
DeclarationInitVariable.o: DeclarationInitVariable.cpp Expression.h DeclarationVariable.h
DeclarationArrayVariable.o: DeclarationArrayVariable.cpp DeclarationVariable.h
GlobalDeclarationVariable.o: GlobalDeclarationVariable.copp Declaration.h MultipleDeclarationVariable.h Printer.h
FunctionCallExpression.o: FunctionCallExpression.cpp  Expression.h
BinaryOperatorExpression.o: BinaryOperatorExpression.cpp Expression.h
UnaryOperatorExpression.o: UnaryOperatorExpression.cpp Expression.h
ExpressionInteger.o: ExpressionInteger.cpp Expression.h
ExpressionVariable.o: ExpressionVariable.cpp Expression.h
CrementVariable.o: CrementVariable.cpp ExpressionVariable.h Expression.h
DeclarationFunctionStatement.o: DeclarationFunctionStatement.cpp Printer.h
DeclarationFunction.o: DeclarationFunction.cpp Declaration.h DeclarationFunctionStatement.h ArgumentList.h Type.h Printer.h
ExpressionSimpleVariable.o: ExpressionSimpleVariable.cpp ExpressionVariable.h
ExpressionArrayVariable.o: ExpressionArrayVariable.cpp ExpressionVariable.h Expression.h
AssignmentVariable.o: AssignmentVariable.cpp ExpressionVariable.h Expression.h
AssignmentOperationVariable.o: AssignmentOperationVariable.cpp AssignmentVariable.h
Return.o: Return.cpp Expression.h Printer.h
SimpleStatement.o: SimpleStatement.cpp Printer.h
ReturnStatement.o: ReturnStatement.cpp SimpleStatement.h Return.h
UselessStatement.o: UselessStatement.cpp SimpleStatement.h
MultipleStatement.o: MultipleStatement.cpp SimpleStatement.h Printer.h
Statement.o: Statement.cpp MultipleStatement.h Printer.h
InitFunctionStatement.o: InitFunctionStatement.cpp DeclarationFunctionStatement.h MultipleStatement.h
BlockDeclarationVariable.o: BlockDeclarationVariable.cpp SimpleStatement.h MultipleDeclarationVariable.h
IterationStatement.o: IterationStatement.cpp SimpleStatement.h Statement.h
SelectionStatement.o: SelectionStatement.cpp SimpleStatement.h Expression.h Statement.h
ExpressionStatement.o: ExpressionStatement.cpp SimpleStatement.h Expression.h
DeclarationVariableStatement.o: DeclarationVariableStatement.cpp SimpleStatement.h
PureDeclarationFunctionStatement.o: PureDeclarationFunctionStatement.cpp DeclarationFunctionStatement.h
LoopExpression.o: LoopExpression.cpp Expression.h Printer.h
WhileLoop.o: WhileLoop.cpp IterationStatement.h Expression.h
ForLoop.o: ForLoop.cpp IterationStatement.h LoopExpression.h

clean:
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c $(BUILDIR)*.o
