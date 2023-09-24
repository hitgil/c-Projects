#ifndef AST_H
#define AST_H

#include <vector>
#include <string>

// Enum to represent different types of AST nodes
enum class NodeType
{
    PROGRAM,
    FUNCTION_DECLARATION,
    VARIABLE_DECLARATION,
    ASSIGNMENT,
    FUNCTION_CALL,
    LITERAL,
    IDENTIFIER,
    // Add more node types as needed
};

// Forward declaration of the ASTNode class
class ASTNode;

// Define a vector type for storing AST nodes
using ASTNodeVector = std::vector<ASTNode *>;

// The base class for all AST nodes
class ASTNode
{
public:
    ASTNode(NodeType type);
    virtual ~ASTNode();

    virtual void print(int level = 0) const;

    NodeType getNodeType() const;

private:
    NodeType nodeType;
};

// Node for representing the entire program
class ProgramNode : public ASTNode
{
public:
    ProgramNode(const ASTNodeVector &statements);
    void print(int level = 0) const;

private:
    ASTNodeVector statements;
};

// Node for function declarations
class FunctionDeclarationNode : public ASTNode
{
public:
    FunctionDeclarationNode(const std::string &name, const ASTNodeVector &parameters, ASTNode *body);
    void print(int level = 0) const;

private:
    std::string name;
    ASTNodeVector parameters;
    ASTNode *body;
};

// Node for variable declarations
class VariableDeclarationNode : public ASTNode
{
public:
    VariableDeclarationNode(const std::string &name, ASTNode *initializer);
    void print(int level = 0) const;

private:
    std::string name;
    ASTNode *initializer;
};

// Node for assignments
class AssignmentNode : public ASTNode
{
public:
    AssignmentNode(const std::string &name, ASTNode *value);
    void print(int level = 0) const;

private:
    std::string name;
    ASTNode *value;
};

// Node for function calls
class FunctionCallNode : public ASTNode
{
public:
    FunctionCallNode(const std::string &name, const ASTNodeVector &arguments);
    void print(int level = 0) const;

private:
    std::string name;
    ASTNodeVector arguments;
};

// Node for literals (e.g., numbers, strings)
class LiteralNode : public ASTNode
{
public:
    LiteralNode(const std::string &value);
    void print(int level = 0) const;

private:
    std::string value;
};

// Node for identifiers (variable names, function names)
class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(const std::string &name);
    void print(int level = 0) const;

private:
    std::string name;
};

#endif // AST_H
