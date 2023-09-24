#include "lexer.h"

Lexer::Lexer(const std::string &sourceCode) : sourceCode(sourceCode), currentPosition(0), currentLine(1)
{
}

char Lexer::getCurrentChar()
{
    if (currentPosition < sourceCode.length())
    {
        return sourceCode[currentPosition];
    }
    else
    {
        return '\0';
    }
}

char Lexer::getNextChar()
{
    if (currentPosition < sourceCode.length())
    {
        currentPosition++;
        return getCurrentChar();
    }
    else
    {
        return '\0';
    }
}

void Lexer::skipWhitespace()
{
    while (isspace(getCurrentChar()))
    {
        if (getCurrentChar() == '\n')
        {
            currentLine++;
        }
        getNextChar();
    }
}

void Lexer::reportError(const std::string &message)
{
    throw std::runtime_error("Error (Line " + std::to_string(currentLine) + "): " + message);
}

void Lexer::reportError(const std::string &message, char c)
{
    reportError(message + " Unexpected character: '" + c + "'");
}

Token Lexer::getNextToken()
{
    skipWhitespace();

    char currentChar = getCurrentChar();

    if (currentChar == '\0')
    {
        return {TOKEN_UNKNOWN, "", currentLine};
    }

    if (isdigit(currentChar))
    {
        std::string lexeme;
        while (isdigit(currentChar))
        {
            lexeme += currentChar;
            currentChar = getNextChar();
        }
        return {TOKEN_INTEGER, lexeme, currentLine};
    }

    if (isalpha(currentChar))
    {
        std::string lexeme;
        while (isalnum(currentChar))
        {
            lexeme += currentChar;
            currentChar = getNextChar();
        }

        if (lexeme == "plus")
        {
            return {TOKEN_PLUS, lexeme, currentLine};
        }
        else if (lexeme == "minus")
        {
            return {TOKEN_MINUS, lexeme, currentLine};
        }

        return {TOKEN_IDENTIFIER, lexeme, currentLine};
    }

    switch (currentChar)
    {
    case '+':
        getNextChar();
        return {TOKEN_PLUS, "+", currentLine};
    case '-':
        getNextChar();
        return {TOKEN_MINUS, "-", currentLine};
    case '*':
        getNextChar();
        return {TOKEN_MULTIPLY, "*", currentLine};
    case '/':
        getNextChar();
        return {TOKEN_DIVIDE, "/", currentLine};
    case '(':
        getNextChar();
        return {TOKEN_LPAREN, "(", currentLine};
    case ')':
        getNextChar();
        return {TOKEN_RPAREN, ")", currentLine};
    default:
        reportError("Unexpected character encountered.", currentChar);
    }
}
