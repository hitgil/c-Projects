#include "semantic_analyzer.h"

SemanticAnalyzer::SemanticAnalyzer()
{

    // Example: Adding predefined variables
    symbolTable["x"] = TOKEN_INT;
    symbolTable["y"] = TOKEN_FLOAT;

    // Example: Adding predefined functions
    functionTable["print"] = std::make_pair(std::vector<TokenType>{TOKEN_STRING}, TOKEN_VOID);
    functionTable["sum"] = std::make_pair(std::vector<TokenType>{TOKEN_INT, TOKEN_INT}, TOKEN_INT);

}

void SemanticAnalyzer::analyze(ASTNode *rootNode)
{
    analyzeNode(rootNode);
}

void SemanticAnalyzer::analyzeNode(ASTNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    if (dynamic_cast<AssignmentNode *>(node))
    {
        analyzeAssignment(static_cast<AssignmentNode *>(node));
    }
    else if (dynamic_cast<VariableDeclarationNode *>(node))
    {
        analyzeVariableDeclaration(static_cast<VariableDeclarationNode *>(node));
    }
    else if (dynamic_cast<FunctionDeclarationNode *>(node))
    {
        analyzeFunctionDeclaration(static_cast<FunctionDeclarationNode *>(node));
    }
    else if (dynamic_cast<FunctionCallNode *>(node))
    {
        analyzeFunctionCall(static_cast<FunctionCallNode *>(node));
    }
    else if (dynamic_cast<IfStatementNode *>(node))
    {
        analyzeIfStatement(static_cast<IfStatementNode *>(node));
    }
    else if (dynamic_cast<WhileStatementNode *>(node))
    {
        analyzeWhileStatement(static_cast<WhileStatementNode *>(node));
    }

    for (ASTNode *child : node->getChildren())
    {
        analyzeNode(child);
    }
}

void SemanticAnalyzer::analyzeAssignment(AssignmentNode *assignment)
{
    std::string variableName = assignment->getVariableName();
    if (symbolTable.find(variableName) == symbolTable.end())
    {
        throw std::runtime_error("Semantic error: Undeclared variable '" + variableName + "'");
    }

    TokenType expectedType = symbolTable[variableName];
    TokenType expressionType = analyzeExpression(assignment->getExpression());

    if (expectedType != expressionType)
    {
        throw std::runtime_error("Semantic error: Type mismatch in assignment to variable '" +
                                 variableName + "'");
    }
}

void SemanticAnalyzer::analyzeVariableDeclaration(VariableDeclarationNode *declaration)
{
    std::string variableName = declaration->getVariableName();
    if (symbolTable.find(variableName) != symbolTable.end())
    {
        throw std::runtime_error("Semantic error: Variable '" + variableName + "' is redefined");
    }

    symbolTable[variableName] = declaration->getVariableType();
}

void SemanticAnalyzer::analyzeFunctionDeclaration(FunctionDeclarationNode *declaration)
{
    std::string functionName = declaration->getFunctionName();
    if (functionTable.find(functionName) != functionTable.end())
    {
        throw std::runtime_error("Semantic error: Function '" + functionName + "' is redefined");
    }

    functionTable[functionName] = std::make_pair(declaration->getParameterTypes(), declaration->getReturnType());
}

void SemanticAnalyzer::analyzeFunctionCall(FunctionCallNode *call)
{
    std::string functionName = call->getFunctionName();
    if (functionTable.find(functionName) == functionTable.end())
    {
        throw std::runtime_error("Semantic error: Undeclared function '" + functionName + "'");
    }

    const std::vector<TokenType> &expectedParamTypes = functionTable[functionName].first;
    const std::vector<ASTNode *> &actualArguments = call->getArguments();

    if (expectedParamTypes.size() != actualArguments.size())
    {
        throw std::runtime_error("Semantic error: Incorrect number of arguments in function call '" +
                                 functionName + "'");
    }

    for (size_t i = 0; i < expectedParamTypes.size(); ++i)
    {
        TokenType expectedType = expectedParamTypes[i];
        TokenType actualType = analyzeExpression(actualArguments[i]);

        if (expectedType != actualType)
        {
            throw std::runtime_error("Semantic error: Type mismatch in argument " +
                                     std::to_string(i + 1) + " of function call '" + functionName + "'");
        }
    }
}

void SemanticAnalyzer::analyzeIfStatement(IfStatementNode *ifStatement)
{
    TokenType conditionType = analyzeExpression(ifStatement->getCondition());
    if (conditionType != TOKEN_BOOL)
    {
        throw std::runtime_error("Semantic error: Condition in 'if' statement must be boolean");
    }

    analyzeNode(ifStatement->getBody());
}

void SemanticAnalyzer::analyzeWhileStatement(WhileStatementNode *whileStatement)
{
    TokenType conditionType = analyzeExpression(whileStatement->getCondition());
    if (conditionType != TOKEN_BOOL)
    {
        throw std::runtime_error("Semantic error: Condition in 'while' statement must be boolean");
    }

    analyzeNode(whileStatement->getBody());
}

TokenType SemanticAnalyzer::analyzeExpression(ASTNode *expr)
{
    if (expr == nullptr)
    {
        return TOKEN_UNKNOWN;
    }

    if (dynamic_cast<BinaryOperationNode *>(expr))
    {
        BinaryOperationNode *binaryExpr = static_cast<BinaryOperationNode *>(expr);
        TokenType leftType = analyzeExpression(binaryExpr->getLeftOperand());
        TokenType rightType = analyzeExpression(binaryExpr->getRightOperand());

        // Perform type checking for binary operation (e.g., addition)
        if (leftType == TOKEN_INT && rightType == TOKEN_INT)
        {
            return TOKEN_INT; // Result type is integer
        }
        else
        {
            throw std::runtime_error("Semantic error: Type mismatch in binary expression");
        }
    }
    else if (dynamic_cast<IdentifierNode *>(expr))
    {
        IdentifierNode *identifier = static_cast<IdentifierNode *>(expr);
        return getIdentifierType(identifier->getName());
    }

    return TOKEN_UNKNOWN;
}

TokenType SemanticAnalyzer::getIdentifierType(const std::string &identifier)
{
    if (symbolTable.find(identifier) != symbolTable.end())
    {
        return symbolTable[identifier];
    }

    throw std::runtime_error("Semantic error: Undeclared variable or identifier '" + identifier + "'");
}
