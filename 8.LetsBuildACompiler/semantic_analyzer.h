#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "ast.h"
#include <stdexcept>
#include <map>
#include <vector>
#include <stdexcept>

class SemanticAnalyzer
{
public:
    SemanticAnalyzer();
    void analyze(ASTNode *rootNode);

private:
    std::map<std::string, TokenType> symbolTable;                                      // For variable tracking
    std::map<std::string, std::pair<std::vector<TokenType>, TokenType>> functionTable; // For function tracking

    void analyzeNode(ASTNode *node);
    void analyzeAssignment(AssignmentNode *assignment);
    void analyzeVariableDeclaration(VariableDeclarationNode *declaration);
    void analyzeFunctionDeclaration(FunctionDeclarationNode *declaration);
    void analyzeFunctionCall(FunctionCallNode *call);
    void analyzeWhileStatement(WhileStatementNode *whileStatement);
    TokenType analyzeExpression(ASTNode *expr);
    TokenType getIdentifierType(const std::string &identifier);
};

#endif // SEMANTIC_ANALYZER_H
