default:
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	clang -o comp *.c
	#g++ -DYYDEBUG -g -o comp lex.yy.c #Non utilise