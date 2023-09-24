#include "parser.h"
#include <stdexcept>

Parser::Parser(Lexer &lexer) : lexer(lexer)
{
    currentToken = lexer.getNextToken();
}

Token Parser::getNextToken()
{
    return lexer.getNextToken();
}

void Parser::match(TokenType expected)
{
    if (currentToken.type == expected)
    {
        currentToken = getNextToken();
    }
    else
    {
        throw std::runtime_error("Parsing error: Expected " + tokenTypeToString(expected) +
                                 " but found " + tokenTypeToString(currentToken.type) +
                                 " at line " + std::to_string(currentToken.line));
    }
}

ASTNode *Parser::parse()
{
    return program();
}

void Parser::program()
{
    while (currentToken.type != TOKEN_UNKNOWN)
    {
        statement();
    }
}

ASTNode *Parser::statement()
{
    if (currentToken.type == TOKEN_IDENTIFIER)
    {
        Token nextToken = lexer.getNextToken();
        if (nextToken.type == TOKEN_ASSIGN)
        {
            return assignmentStatement();
        }
        else if (nextToken.type == TOKEN_SEMICOLON)
        {
            return variableDeclaration();
        }
    }
    else if (currentToken.type == TOKEN_FUNCTION)
    {
        return functionDeclaration();
    }
    else if (currentToken.type == TOKEN_IF)
    {
        return ifStatement();
    }
    else if (currentToken.type == TOKEN_WHILE)
    {
        return whileStatement();
    }
    else
    {
        throw std::runtime_error("Parsing error: Unexpected token " + tokenTypeToString(currentToken.type) +
                                 " at line " + std::to_string(currentToken.line));
    }
    return nullptr;
}

ASTNode *Parser::assignmentStatement()
{
    std::string variableName = currentToken.lexeme;
    match(TOKEN_IDENTIFIER);
    match(TOKEN_ASSIGN);
    ASTNode *expr = expression();
    match(TOKEN_SEMICOLON);
    return new AssignmentNode(variableName, expr);
}

ASTNode *Parser::variableDeclaration()
{
    TokenType variableType = currentToken.type;
    match(TOKEN_TYPE);
    std::string variableName = currentToken.lexeme;
    match(TOKEN_IDENTIFIER);
    match(TOKEN_SEMICOLON);
    return new VariableDeclarationNode(variableType, variableName);
}

ASTNode *Parser::expression()
{
    // Implement expression parsing here
    // For simplicity, returning null
    return nullptr;
}

ASTNode *Parser::ifStatement()
{
    match(TOKEN_IF);
    match(TOKEN_LPAREN);
    ASTNode *condition = expression();
    match(TOKEN_RPAREN);
    ASTNode *ifBody = statement();
    return new IfStatementNode(condition, ifBody);
}

ASTNode *Parser::whileStatement()
{
    match(TOKEN_WHILE);
    match(TOKEN_LPAREN);
    ASTNode *condition = expression();
    match(TOKEN_RPAREN);
    ASTNode *whileBody = statement();
    return new WhileStatementNode(condition, whileBody);
}

std::string Parser::tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TOKEN_INTEGER:
        return "integer";
    case TOKEN_IDENTIFIER:
        return "identifier";
    case TOKEN_PLUS:
        return "+";
    case TOKEN_MINUS:
        return "-";
    case TOKEN_MULTIPLY:
        return "*";
    case TOKEN_DIVIDE:
        return "/";
    case TOKEN_LPAREN:
        return "(";
    case TOKEN_RPAREN:
        return ")";
    case TOKEN_SEMICOLON:
        return ";";
    case TOKEN_ASSIGN:
        return "=";
    case TOKEN_TYPE:
        return "type";
    case TOKEN_FUNCTION:
        return "function";
    case TOKEN_IF:
        return "if";
    case TOKEN_WHILE:
        return "while";
    case TOKEN_UNKNOWN:
        return "unknown";
    default:
        return "unexpected";
    }
}
