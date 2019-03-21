#include <assert.h>
#include <stdio.h>

#include "lexer/lexer.h"
#include "token/token.h"

void test_lexer() {

  token_t tokens[] = {
    {ASSIGN, "="},
    {PLUS, "+"},
    {LPAREN, "("},
    {RPAREN, ")"},
    {LBRACE, "["},
    {RBRACE, "]"},
    {COMMA, ","},
    {SEMICOLON, ";"},
    {END, ""},
  };

  const char *input = "=+(){},;";
  lexer_t l = newLexer(input);

  for (int i = 0; i < 8; i++) {
    token_t t = nextToken(&l);
    token_t te = tokens[i];
    printf("Token{%s, '%s'} actual != Token{%s, '%s'}\n",
        token_types_display[t.type], t.literal,
        token_types_display[te.type], te.literal);
    assert (te.type == t.type);
  }
}

int main() {
  test_lexer();
}
