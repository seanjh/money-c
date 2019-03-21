#ifndef LEXER
#define LEXER

#include "../token/token.h"

typedef struct lexer_struct {
  const char  *input;
  int         length;
  int         position;
  int         readPosition;
  char        ch;
} lexer_t;

lexer_t newLexer(const char *input);
token_t nextToken(lexer_t *);

#endif
