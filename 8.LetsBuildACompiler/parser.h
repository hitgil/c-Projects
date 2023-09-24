#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"
#include <map>
#include <vector>

class Parser
{
public:
    Parser(Lexer &lexer);
    ASTNode *parse();

private:
    Lexer &lexer;
    Token currentToken;
    std::map<std::string, int> symbolTable; // For variable tracking
    std::vector<std::string> currentScope;  // For scope management

    Token getNextToken();
    void match(TokenType expected);
    void program();
    ASTNode *statement();
    ASTNode *assignmentStatement();
    ASTNode *variableDeclaration();
    ASTNode *expression();
    ASTNode *term();
    ASTNode *factor();
    ASTNode *functionDeclaration();
    ASTNode *functionCall();
    ASTNode *ifStatement();
    ASTNode *whileStatement();
};

#endif // PARSER_H
