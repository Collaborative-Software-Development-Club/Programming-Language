#include <iostream>
#include <string>
#include "scanner.cpp" // Include the Scanner class

using namespace std;

#ifndef PARSER_H
#define PARSER_H

// Error handling cases for throwing token-related errors
class ErrorThrow {
    public:
        // Token names for debugging and error messages
        static constexpr const char* tokenNames[] = {
            "PROGRAM", "NAME", "ASSIGN", "SEMICOLON", "PRINT", "IF", "ELIF", "ELSE", "WHILE",
            "LPAREN", "RPAREN", "LCURL", "RCURL", "NOT", "OR", "AND", "EQUAL", "NOTEQUAL", 
            "LT", "GT", "LTE", "GTE", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "POWER", "MOD", "NUMBER", "INT", "EOS"
        };

        // Method to ensure that the current token matches the expected one
        static void consume(Scanner& scanner, simple expected, simple& currentToken) {
            if (currentToken != expected) {
                cerr << "Error: Expected " << tokenNames[expected] << ", but got " << tokenNames[currentToken] << endl;
                exit(1); // Exit on error
            }
            
            // Debugging output for consumed token
            cout << "Consumed token: " << tokenNames[currentToken] << endl;

            // Advance to the next token
            scanner.nextToken();
            currentToken = scanner.currentToken();
        }
};

// Parser class responsible for initiating the parsing process
class Parser {
    public:
        Scanner scanner; // Scanner object for tokenization
        simple currentToken;
        Program program; // Main program object to be parsed

        // Constructor to initialize parser with the input file
        Parser(const string& filename) : scanner(filename) {
            scanner.nextToken();                   // Get the first token
            currentToken = scanner.currentToken(); // Set the currentToken
        }

        // Parse the entire program
        void parse() {
            program.parse(scanner, currentToken);
        }
};

// Class representing the entire program structure
class Program {
    StatementSeq statementSeq; // Sequence of statements in the program
    string programName;

    public:
        // Parse the program structure
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, PROGRAM, currentToken); // Expect PROGRAM token
            ErrorThrow::consume(scanner, NAME, currentToken);    // Expect NAME token
            programName = scanner.getName();                     // Store the program name

            ErrorThrow::consume(scanner, LCURL, currentToken);   // Expect LCURL token
            statementSeq.parse(scanner, currentToken);           // Parse the statement sequence
            ErrorThrow::consume(scanner, RCURL, currentToken);   // Expect RCURL token
        }
};

// Class to handle a sequence of statements
class StatementSeq {
    Statement statement; // Individual statement object

    public:
        // Parse a sequence of statements
        void parse(Scanner& scanner, simple& currentToken) {
            statement.parse(scanner, currentToken); // Parse the first statement

            // Keep parsing until the end of the block or end of file (EOS)
            while (currentToken != RCURL && currentToken != EOS) statement.parse(scanner, currentToken);
        }

};

// Class to parse indiviual statements (e.g. assignment, if-block, etc.)
class Statement {
    Assign assign;
    If ifBlock;
    Loop loop;
    Print print;
    Declare declare;

    public:
        // Parse a single statement
        void parse(Scanner& scanner, simple& currentToken) {
            if      (currentToken == NAME)  assign.parse(scanner, currentToken);  // Assignment
            else if (currentToken == IF)    ifBlock.parse(scanner, currentToken); // If-block
            else if (currentToken == WHILE) loop.parse(scanner, currentToken);    // Loop
            else if (currentToken == PRINT) print.parse(scanner, currentToken);   // Print statement
            else if (currentToken == INT)   declare.parse(scanner, currentToken); // Declaration
            else {
                cerr << "Error: Unexpected statement token: " << ErrorThrow::tokenNames[currentToken] << endl;
                exit(1); // Exit on error
            }
        }
};

// Class for assignment statements (e.g. variable = expression)
class Assign {
    Expression expression;

    public:
        // Parse an assignment statement
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, NAME, currentToken);   // Expect NAME token
            ErrorThrow::consume(scanner, ASSIGN, currentToken); // Expect ASSIGN token
            expression.parse(scanner, currentToken);            // Parse the expression on the right-hand side
        }
};

// Class to handle if, elif, and else blocks
class If {
    Condition condition;
    StatementSeq statementSeq;

    public:
        // Parse an if-block with optional elif and else 
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, IF, currentToken); // Expect IF token
            condition.parse(scanner, currentToken);         // Parse the condition

            ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
            statementSeq.parse(scanner, currentToken);         // Parse the statements inside the if block
            ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token

            // Optionally parse elif chain
            while (currentToken == ELIF) {
                ErrorThrow::consume(scanner, ELIF, currentToken); // Expect ELIF token
                condition.parse(scanner, currentToken);           // Parse the condition

                ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
                statementSeq.parse(scanner, currentToken);         // Parse the statements inside the if block
                ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
            }

            // Handle optional else block
            if (currentToken == ELSE) {
                ErrorThrow::consume(scanner, ELSE, currentToken);  // Expect ELSE token
                ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
                statementSeq.parse(scanner, currentToken);         // Parse the statements inside the if block
                ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
            }
        }
};

// Class for parsing loops
class Loop {
    Condition condition;
    StatementSeq statementSeq;

    public:
        // Parse a while loop
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, WHILE, currentToken); // Expect WHILE token
            condition.parse(scanner, currentToken);            // Parse the condition

            ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURl token
            statementSeq.parse(scanner, currentToken);         // Parse the statements inside the loop
            ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
        }
};

// Class for parsing print statements
class Print {
    Expression expression;

    public:
        // Parse a print statement
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, PRINT, currentToken);  // Expect PRINT token
            ErrorThrow::consume(scanner, LPAREN, currentToken); // Expect LPAREN token
            expression.parse(scanner, currentToken);            // Parse the expression to print
            ErrorThrow::consume(scanner, RPAREN, currentToken); // Expect RPAREN token
        }
};

// Class for variable declarations (e.g. int x)
class Declare {
    public:
        // Parse a variable declaration
        void parse(Scanner& scanner, simple& currentToken) {
            ErrorThrow::consume(scanner, INT, currentToken);  // Expect INT token
            ErrorThrow::consume(scanner, NAME, currentToken); // Expect NAME token
        }
};

// Class for parsing expressions (e.g. arithmetic operations)
class Expression {
    Term term;

    public:
        // Parse an expression
        void parse(Scanner& scanner, simple& currentToken) {
            term.parse(scanner, currentToken); // Parse the first term

            // Handle addition or subtraction operations
            while (currentToken == ADD || currentToken == SUBTRACT) {
                ErrorThrow::consume(scanner, currentToken, currentToken); // Consume the operator
                term.parse(scanner, currentToken);                        // Parse the next term
            }
        }
};

// Class for parsing conditions (e.g. logical expressions)
class Condition {
    Compare compare;

    public:
        // Parse a condition
        void parse(Scanner& scanner, simple& currentToken) {
            if (currentToken == NOT) {
                ErrorThrow::consume(scanner, NOT, currentToken); // Expect NOT token
                parse(scanner, currentToken);                    // Recursively parse the condition
            } else compare.parse(scanner, currentToken);         // Parse the comparison expression

            // Handle logical operators (AND, OR)
            while (currentToken == AND || currentToken == OR) {
                ErrorThrow::consume(scanner, currentToken, currentToken); // Consume the operator
                parse(scanner, currentToken);                             // Parse the next condition
            }
        }
};

// Class for parsing terms in expressions (e.g. factors with operators)
class Term {
    Factor factor;

    public:
        // Parse a term
        void parse(Scanner& scanner, simple& currentToken) {
            factor.parse(scanner, currentToken); // Parse the first factor

            // Handle multiplication, division, etc.
            while (currentToken == POWER || currentToken == MULTIPLY || currentToken == DIVIDE || currentToken == MOD) {
                ErrorThrow::consume(scanner, currentToken, currentToken); // Consume the operator
                factor.parse(scanner, currentToken);                      // Parse the next factor
            }
        }
};

// Class for handling comparison expressions (e.g. ==, !=, <, >, etc.)
class Compare {
    Expression expression;

    public:
        // Parse a comparison expression
        void parse(Scanner& scanner, simple& currentToken) {
            expression.parse(scanner, currentToken); // Parse the left-hand expression

            // Handle comparison operators
            if (currentToken == EQUAL || currentToken == NOTEQUAL || currentToken == LT || currentToken == GT || currentToken == LTE || currentToken == GTE) {
                ErrorThrow::consume(scanner, currentToken, currentToken); // Consume the operator
                expression.parse(scanner, currentToken);                  // Parse the right-hand expression
            }
        }
};

// Class for parsing factors (basic values or enclosed expressions)
class Factor {
    Expression expression;

    public:
        // Parse a factor
        void parse(Scanner& scanner, simple& currentToken) {
            if (currentToken == NAME || currentToken == NUMBER) ErrorThrow::consume(scanner, currentToken, currentToken); // Consume NAME or NUMBER
            else if (currentToken == LPAREN) {
                ErrorThrow::consume(scanner, LPAREN, currentToken);   // Expect LPAREN token
                expression.parse(scanner, currentToken);              // Parse the enclosed expression
                ErrorThrow::consume(scanner, RPAREN, currentToken);   // Expect RPAREN token
            } else {
                cerr << "Error: Unexpected factor: " << ErrorThrow::tokenNames[currentToken] << endl;
                exit(1); // Exit on error
            }
        }
};

#endif