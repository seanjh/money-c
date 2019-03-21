#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "../token/token.h"

void readChar(lexer_t *l) {
  int readPosition = l->readPosition;

  if (readPosition >= l->length) {
    l->ch = 0;
  } else {
    l->ch = l->input[readPosition];
  }
  l->position = readPosition;
  l->readPosition++;
}

lexer_t newLexer(const char *input) {
  lexer_t l = {
    .input=input,
    .length=strlen(input),
    .position=0,
    .readPosition=0,
    .ch=0,
  };
  readChar(&l);

  return l;
}

token_t newToken(token_type type, const char *literal) {
  return (token_t){
    .type=type,
    .literal=literal,
  };
}

int isLetter(char ch) {
  return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

char *readIdentifier(lexer_t *l) {
  int position = l->position;
  int num = 0;
  while (isLetter(l->ch)) {
    readChar(l);
    num++;
  }
  const char *start = l->input + position;
  return strndup(start, num);
}

token_t nextToken(lexer_t *l) {
  token_t t;

  char c = l->ch;
  switch (c) {
    case '=':
      t = newToken(ASSIGN, "=");
      break;
    case ';':
      t = newToken(SEMICOLON, ";");
      break;
    case '(':
      t = newToken(LPAREN, "(");
      break;
    case ')':
      t = newToken(RPAREN, ")");
      break;
    case ',':
      t = newToken(COMMA, ",");
      break;
    case '+':
      t = newToken(PLUS, "+");
      break;
    case '{':
      t = newToken(LBRACE, "{");
      break;
    case '}':
      t = newToken(RBRACE, "}");
      break;
    case 0:
      t = newToken(END, "");
      break;
    default:
      1 / 0;
  }

  readChar(l);
  return t;
}
