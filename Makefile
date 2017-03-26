default:
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	g++ -std=c++11 -DYYDEBUG -o comp *.c
clean:
	rm comp comp.tab.c comp.tab.h comp.output lex.yy.c
