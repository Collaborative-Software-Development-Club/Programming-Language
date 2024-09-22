#include <iostream>
#include <string>
#include "scanner.cpp" // Include the Scanner class

using namespace std;

#ifndef PARSER_H
#define PARSER_H

// Token names for debugging and error messages
static const string tokenNames[] = {
    "PROGRAM", "NAME", "ASSIGN", "SEMICOLON", "PRINT", "IF", "ELIF", "ELSE", "WHILE",
    "LPAREN", "RPAREN", "LCURL", "RCURL", "NOT", "OR", "AND", "EQUAL", "NOTEQUAL", 
    "LT", "GT", "LTE", "GTE", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "POWER", "MOD", "NUMBER", "INT", "EOS"
};

class Parser {
    private:
        // Scanner object for tokenization
        Scanner scanner;

        // Cureent token being processed
        simple currentToken;

    public:
        // Constructor: Initializes the scanner and gets the first token
        Parser(string filename) : scanner(filename) {
            // Advance to the next token
            scanner.nextToken();

            // Set the current token
            currentToken = scanner.currentToken();
        }

        // Method to consume the current token and move to the next one
        void consume(simple expected) {
            if (currentToken != expected) {
                cerr << "Error: Expected " << tokenNames[expected] << ", but got " << tokenNames[currentToken] << endl;
                exit(1);
            }

            // Debug output
            cout << "Consumed Token: " << tokenNames[currentToken] << endl;

            // Advance to the next token
            scanner.nextToken();

            // Update the current token
            currentToken = scanner.currentToken();
        }

        // Parses the entire program
        void parseProgram() {
            consume(PROGRAM);    // Expect PROGRAM token
            consume(NAME);       // Expect NAME token
            consume(LCURL);      // Expect LCURL token
            parseStatementSeq(); // Parse statements inside the program
            consume(RCURL);      // Expect RCURL token
        }

        // Parses a sequence of statements
        void parseStatementSeq() {
            // Parse the first statement
            parseStatement();

            // Continue parsing statements until reaching the end of the block or EOS
            while (currentToken != RCURL && currentToken != EOS) parseStatement();
        }

        // Parses a single statement
        void parseStatement() {
            // Determine the type of statement based on the current token
            if      (currentToken == NAME)  parseAssign();
            else if (currentToken == IF)    parseIf();
            else if (currentToken == WHILE) parseLoop();
            else if (currentToken == PRINT) parsePrint();
            else if (currentToken == INT)   parseDeclare();
            else {
                cerr << "Error: Unexpected statement token: " << tokenNames[currentToken] << endl;

                // Exit on unexpected token
                exit(1);
            }
        }

        // Parse an assignment statement
        void parseAssign() {
            consume(NAME);     // Expect NAME token
            consume(ASSIGN);   // Expect ASSIGN token
            parseExpression(); // Parse the expression on the right-hand side
        }

        // Parses an if statement
        void parseIf() {
            consume(IF);         // Expect IF token
            parseCondition();    // Parse the condition
            consume(LCURL);      // Expect LCURL token
            parseStatementSeq(); // Parse the statements inside the if block
            consume(RCURL);      // Expect RCURL token

            // Optionally parse elif chain
            while (currentToken == ELIF) {
                consume(ELIF);       // Expect ELIF token
                parseCondition();    // Parse the condition
                consume(LCURL);      // Expect LCURL token 
                parseStatementSeq(); // Parse the statements inside the elif block
                consume(RCURL);      // Expect RCURL token
            }

            // Check for an else block
            if (currentToken == ELSE) {
                consume(ELSE);       // Expect ELSE token
                consume(LCURL);      // Expect LCURL token
                parseStatementSeq(); // Parse the statements inside the else block
                consume(RCURL);      // Expect RCURL token
            }
        }

        // Parses a while loop
        void parseLoop() {
            consume(WHILE);      // Expect WHILE token
            parseCondition();    // Parse the condition
            consume(LCURL);      // Expect LCURl token
            parseStatementSeq(); // Parse the statements inside the loop
            consume(RCURL);      // Expect RCURL token
        }
        
        // Parses a print statement
        void parsePrint() {
            consume(PRINT);    // Expect PRINT token
            consume(LPAREN);   // Expect LPAREN token
            parseExpression(); // Parse the expression to print
            consume(RPAREN);   // Expect RPAREN token
        }

        // Parses a variable declaration
        void parseDeclare() {
            consume(INT);  // Expect INT token
            consume(NAME); // Expect NAME token
        }

        // Parses an expression (handles terms and operators)
        void parseExpression() {
            // Parse the first term
            parseTerm();

            // Optionally parse ADD/SUBTRACT expressions
            while (currentToken == ADD || currentToken == SUBTRACT) {
                // Consume the operator
                consume(currentToken);

                // Parse the next term
                parseTerm();
            }
        }
        
        // Parses a condition (handles logical expressions)
        void parseCondition() {
            if (currentToken == NOT) {
                consume(NOT);      // Expect NOT token
                parseCondition();  // Recursively parse the condition
            } else parseCompare(); // Parse the comparison expression

            // Optionally parse AND/OR conditions
            while (currentToken == AND || currentToken == OR) {
                consume(currentToken); // Consume the operator
                parseCondition();      // Parse the next condition
            }
        }

        // Parses a term (handles factors and operators)
        void parseTerm() {
            // Parse the first factor
            parseFactor();

            // Handle POWER, MULTIPLY, DIVIDE, MOD
            while (currentToken == POWER || currentToken == MULTIPLY || currentToken == DIVIDE || currentToken == MOD) {
                consume(currentToken); // Consume the operator
                parseFactor();         // Parse the next factor
            }
        }

        // Parses a comparison expression
        void parseCompare() {
            // Parse the left-hand side
            parseExpression();

            // Handle comparison operators
            if (currentToken == EQUAL || currentToken == NOTEQUAL || currentToken == LT || currentToken == GT || currentToken == LTE || currentToken == GTE) {
                consume(currentToken); // Consume the operator
                parseExpression();     // Parse the right-hand side
            }
        }

        // Parses a factor (handles basic values)
        void parseFactor() {
            if (currentToken == NAME || currentToken == NUMBER) consume(currentToken); // Consume NAME or NUMBER
            else if (currentToken == LPAREN) {
                consume(LPAREN);   // Consume LPAREN token
                parseExpression(); // Parse the enclosed expression
                consume(RPAREN);   // Expect RPAREN token
            } else {
                cerr << "Error: Unexpected factor: " << tokenNames[currentToken] << endl;

                // Exit on unexpected factor
                exit(1);
            }
        }
};

#endif