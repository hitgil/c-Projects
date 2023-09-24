#include "ast.h"
#include <iostream>

// ASTNode methods
ASTNode::ASTNode(NodeType type) : nodeType(type) {}

void ASTNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Node Type: " << static_cast<int>(nodeType) << std::endl;
}

// ProgramNode methods
ProgramNode::ProgramNode(const std::vector<ASTNode *> &statements) : ASTNode(NodeType::PROGRAM), statements(statements) {}

void ProgramNode::print(int level) const
{
    std::cout << "Program:" << std::endl;
    for (const ASTNode *statement : statements)
    {
        statement->print(level + 1);
    }
}

// FunctionDeclarationNode methods
FunctionDeclarationNode::FunctionDeclarationNode(const std::string &name, const std::vector<std::string> &parameters, ASTNode *body)
    : ASTNode(NodeType::FUNCTION_DECLARATION), name(name), parameters(parameters), body(body) {}

void FunctionDeclarationNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Function Declaration: " << name << std::endl;
    std::cout << "Parameters:" << std::endl;
    for (const std::string &param : parameters)
    {
        for (int i = 0; i < level + 1; ++i)
        {
            std::cout << "  ";
        }
        std::cout << param << std::endl;
    }
    body->print(level + 1);
}

// VariableDeclarationNode methods
VariableDeclarationNode::VariableDeclarationNode(const std::string &name, ASTNode *initializer)
    : ASTNode(NodeType::VARIABLE_DECLARATION), name(name), initializer(initializer) {}

void VariableDeclarationNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Variable Declaration: " << name << std::endl;
    if (initializer)
    {
        initializer->print(level + 1);
    }
}

// AssignmentNode methods
AssignmentNode::AssignmentNode(const std::string &name, ASTNode *value)
    : ASTNode(NodeType::ASSIGNMENT), name(name), value(value) {}

void AssignmentNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Assignment: " << name << std::endl;
    value->print(level + 1);
}

// FunctionCallNode methods
FunctionCallNode::FunctionCallNode(const std::string &name, const std::vector<ASTNode *> &arguments)
    : ASTNode(NodeType::FUNCTION_CALL), name(name), arguments(arguments) {}

void FunctionCallNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Function Call: " << name << std::endl;
    for (const ASTNode *arg : arguments)
    {
        arg->print(level + 1);
    }
}

// LiteralNode methods
LiteralNode::LiteralNode(const std::string &value) : ASTNode(NodeType::LITERAL), value(value) {}

void LiteralNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Literal: " << value << std::endl;
}

// IdentifierNode methods
IdentifierNode::IdentifierNode(const std::string &name) : ASTNode(NodeType::IDENTIFIER), name(name) {}

void IdentifierNode::print(int level) const
{
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Identifier: " << name << std::endl;
}

