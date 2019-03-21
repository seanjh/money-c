CC			=	gcc
CFLAGS  = -g -Wall

OBJS		= lexer/lexer.o

monkey: $(OBJS) repl/repl.o 
	$(CC) $(CFLAGS) -o monkey $(OBJS) repl/repl.o

lexer.o:	lexer/lexer.c
repl.o: 	repl/repl.c

.PHONY: clean test

test: lexer/lexer.o
	@$(CC) $(CFLAGS) -o monkey-test test.c lexer/lexer.o
	@./monkey-test
	@rm monkey-test

clean:
	rm monkey $(OBJS) repl/repl.o 
