#ifndef TOKEN
#define TOKEN

typedef enum token_type_enum {
  ILLEGAL,
  END,

  // Identifiers + literals
  IDENT,      // add, foobar, x, y, ...
  INT,        // 1343456

  // Operators
  ASSIGN,     // =
  PLUS,       // +

  // Delimiters
  COMMA,      // ,
  SEMICOLON,  // ;
  LPAREN,     // (
  RPAREN,     // )
  LBRACE,     // {
  RBRACE,     // }

  // Keywords
  FUNCTION,
  LET,
} token_type;

static const char *token_types_display[] = {
  "ILLEGAL",
  "EOF",
  "IDENT",
  "INT",
  "=",
  "+",
  ",",
  ";",
  "(",
  ")",
  "{",
  "}",
  "FUNCTION",
  "LET",
};

typedef struct token {
  token_type type;
  const char *literal;
} token_t;

#endif
