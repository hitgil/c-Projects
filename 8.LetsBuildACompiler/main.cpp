#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "ast.h"

int main()
{
    // Read the source code from a file or user input
    std::string sourceCode = "int main() { int x = 5; return x; }";

    // Initialize the lexer with the source code
    Lexer lexer(sourceCode);

    // Initialize the parser with the lexer
    Parser parser(lexer);

    try
    {
        // Parse the source code and generate the AST
        ASTNode *ast = parser.parse();

        // Perform semantic analysis
        SemanticAnalyzer semanticAnalyzer;
        semanticAnalyzer.analyze(ast);

        // Print the parsed AST (for simplicity)
        ast->print();

        // Clean up and release resources
        delete ast;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
