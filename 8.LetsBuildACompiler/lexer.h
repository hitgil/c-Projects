#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Define token types
enum TokenType
{
    TOKEN_UNKNOWN,
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
};

// Token structure
struct Token
{
    TokenType type;
    std::string lexeme;
    int line; 
};

class Lexer
{
public:
    Lexer(const std::string &sourceCode);
    Token getNextToken();

private:
    std::string sourceCode;
    size_t currentPosition;
    int currentLine;

    char getCurrentChar();
    char getNextChar();
    void skipWhitespace();
    void reportError(const std::string &message);
    void reportError(const std::string &message, char c);
};

#endif 
