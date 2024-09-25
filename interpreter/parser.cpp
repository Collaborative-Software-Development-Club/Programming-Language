#include <iostream>
#include <string>
#include "scanner.cpp" // Include the Scanner class

using namespace std;

#ifndef PARSER_H
#define PARSER_H

// Forward declarations for classes
class Program;
class StatementSeq;
class Statement;
class Assign;
class Print;
class If;
class Loop;
class Declare;
class Expression;
class Condition;
class Compare;
class Term;
class Factor;

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
    Program* program; // Pointer to the main program object to be parsed

    // Constructor to initialize parser with the input file
    Parser(const string& filename) : scanner(filename), program(nullptr) {
        scanner.nextToken();                   // Get the first token
        currentToken = scanner.currentToken(); // Set the currentToken
    }

    // Parse the entire program
    void parse() {
        program = new Program(); // Allocate memory for Program
        program->parse(scanner, currentToken);
    }

    ~Parser() {
        delete program; // Free memory allocated for program
    }
};

// Class representing the entire program structure
class Program {
    StatementSeq* statementSeq; // Pointer to sequence of statements in the program
    string programName;

public:
    Program() : statementSeq(nullptr) {} // Initialize statementSeq to nullptr

    // Parse the program structure
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, PROGRAM, currentToken); // Expect PROGRAM token
        ErrorThrow::consume(scanner, NAME, currentToken);    // Expect NAME token
        programName = scanner.getName();                     // Store the program name

        ErrorThrow::consume(scanner, LCURL, currentToken);   // Expect LCURL token
        statementSeq = new StatementSeq();                    // Allocate memory for StatementSeq
        statementSeq->parse(scanner, currentToken);           // Parse the statement sequence
        ErrorThrow::consume(scanner, RCURL, currentToken);   // Expect RCURL token
    }

    ~Program() {
        delete statementSeq; // Free memory allocated for statementSeq
    }
};

// Class to handle a sequence of statements
class StatementSeq {
    Statement* statement; // Pointer to individual statement object

public:
    StatementSeq() : statement(nullptr) {} // Initialize statement to nullptr

    // Parse a sequence of statements
    void parse(Scanner& scanner, simple& currentToken) {
        statement = new Statement(); // Allocate memory for Statement
        statement->parse(scanner, currentToken); // Parse the first statement

        // Keep parsing until the end of the block or end of file (EOS)
        while (currentToken != RCURL && currentToken != EOS) {
            statement->parse(scanner, currentToken); // Parse subsequent statements
        }
    }

    ~StatementSeq() {
        delete statement; // Free memory allocated for statement
    }
};

// Class to parse individual statements (e.g. assignment, if-block, etc.)
class Statement {
    Assign* assign;
    If* ifBlock;
    Loop* loop;
    Print* print;
    Declare* declare;

public:
    Statement() : assign(nullptr), ifBlock(nullptr), loop(nullptr), print(nullptr), declare(nullptr) {}

    // Parse a single statement
    void parse(Scanner& scanner, simple& currentToken) {
        if (currentToken == NAME) {
            assign = new Assign(); // Allocate memory for Assign
            assign->parse(scanner, currentToken); // Assignment
        } else if (currentToken == IF) {
            ifBlock = new If(); // Allocate memory for If
            ifBlock->parse(scanner, currentToken); // If-block
        } else if (currentToken == WHILE) {
            loop = new Loop(); // Allocate memory for Loop
            loop->parse(scanner, currentToken); // Loop
        } else if (currentToken == PRINT) {
            print = new Print(); // Allocate memory for Print
            print->parse(scanner, currentToken); // Print statement
        } else if (currentToken == INT) {
            declare = new Declare(); // Allocate memory for Declare
            declare->parse(scanner, currentToken); // Declaration
        } else {
            cerr << "Error: Unexpected statement token: " << ErrorThrow::tokenNames[currentToken] << endl;
            exit(1); // Exit on error
        }
    }

    ~Statement() {
        delete assign;   // Free memory allocated for assign
        delete ifBlock;  // Free memory allocated for ifBlock
        delete loop;     // Free memory allocated for loop
        delete print;    // Free memory allocated for print
        delete declare;  // Free memory allocated for declare
    }
};

// Class for assignment statements (e.g. variable = expression)
class Assign {
    Expression* expression; // Pointer to Expression

public:
    Assign() : expression(nullptr) {} // Initialize expression to nullptr

    // Parse an assignment statement
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, NAME, currentToken);   // Expect NAME token
        ErrorThrow::consume(scanner, ASSIGN, currentToken); // Expect ASSIGN token
        expression = new Expression(); // Allocate memory for Expression
        expression->parse(scanner, currentToken);            // Parse the expression on the right-hand side
    }

    ~Assign() {
        delete expression; // Free memory allocated for expression
    }
};

// Class to handle if, elif, and else blocks
class If {
    Condition* condition;      // Pointer to Condition
    StatementSeq* statementSeq; // Pointer to StatementSeq

public:
    If() : condition(nullptr), statementSeq(nullptr) {} // Initialize pointers to nullptr

    // Parse an if-block with optional elif and else 
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, IF, currentToken); // Expect IF token
        condition = new Condition(); // Allocate memory for Condition
        condition->parse(scanner, currentToken);         // Parse the condition

        ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
        statementSeq = new StatementSeq(); // Allocate memory for StatementSeq
        statementSeq->parse(scanner, currentToken);         // Parse the statements inside the if block
        ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token

        // Optionally parse elif chain
        while (currentToken == ELIF) {
            ErrorThrow::consume(scanner, ELIF, currentToken); // Expect ELIF token
            condition = new Condition(); // Allocate memory for Condition
            condition->parse(scanner, currentToken);           // Parse the condition

            ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
            statementSeq = new StatementSeq(); // Allocate memory for StatementSeq
            statementSeq->parse(scanner, currentToken);         // Parse the statements inside the if block
            ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
        }

        // Handle optional else block
        if (currentToken == ELSE) {
            ErrorThrow::consume(scanner, ELSE, currentToken);  // Expect ELSE token
            ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
            statementSeq = new StatementSeq(); // Allocate memory for StatementSeq
            statementSeq->parse(scanner, currentToken);         // Parse the statements inside the if block
            ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
        }
    }

    ~If() {
        delete condition;     // Free memory allocated for condition
        delete statementSeq;  // Free memory allocated for statementSeq
    }
};

// Class for parsing loops
class Loop {
    Condition* condition;      // Pointer to Condition
    StatementSeq* statementSeq; // Pointer to StatementSeq

public:
    Loop() : condition(nullptr), statementSeq(nullptr) {} // Initialize pointers to nullptr

    // Parse a while-loop
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, WHILE, currentToken); // Expect WHILE token
        condition = new Condition(); // Allocate memory for Condition
        condition->parse(scanner, currentToken);           // Parse the condition

        ErrorThrow::consume(scanner, LCURL, currentToken); // Expect LCURL token
        statementSeq = new StatementSeq(); // Allocate memory for StatementSeq
        statementSeq->parse(scanner, currentToken);         // Parse the statements inside the while block
        ErrorThrow::consume(scanner, RCURL, currentToken); // Expect RCURL token
    }

    ~Loop() {
        delete condition;     // Free memory allocated for condition
        delete statementSeq;  // Free memory allocated for statementSeq
    }
};

// Class for print statements
class Print {
    Expression* expression; // Pointer to Expression

public:
    Print() : expression(nullptr) {} // Initialize expression to nullptr

    // Parse a print statement
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, PRINT, currentToken); // Expect PRINT token
        ErrorThrow::consume(scanner, LPAREN, currentToken); // Expect LPAREN token
        expression = new Expression(); // Allocate memory for Expression
        expression->parse(scanner, currentToken);            // Parse the expression to be printed
        ErrorThrow::consume(scanner, RPAREN, currentToken); // Expect RPAREN token
        ErrorThrow::consume(scanner, SEMICOLON, currentToken); // Expect SEMICOLON token
    }

    ~Print() {
        delete expression; // Free memory allocated for expression
    }
};

// Class for variable declarations
class Declare {
    string name;          // Variable name
    Expression* expression; // Pointer to Expression

public:
    Declare() : expression(nullptr) {} // Initialize expression to nullptr

    // Parse a variable declaration
    void parse(Scanner& scanner, simple& currentToken) {
        ErrorThrow::consume(scanner, INT, currentToken);   // Expect INT token
        ErrorThrow::consume(scanner, NAME, currentToken);  // Expect NAME token
        name = scanner.getName();                          // Store the variable name
        ErrorThrow::consume(scanner, ASSIGN, currentToken); // Expect ASSIGN token
        expression = new Expression(); // Allocate memory for Expression
        expression->parse(scanner, currentToken);           // Parse the assigned expression
        ErrorThrow::consume(scanner, SEMICOLON, currentToken); // Expect SEMICOLON token
    }

    ~Declare() {
        delete expression; // Free memory allocated for expression
    }
};

// Class for handling expressions
class Expression {
    Term* term;            // Pointer to Term
    Expression* next;      // Pointer to next Expression (for handling chains)

public:
    Expression() : term(nullptr), next(nullptr) {} // Initialize pointers to nullptr

    // Parse an expression
    void parse(Scanner& scanner, simple& currentToken) {
        term = new Term(); // Allocate memory for Term
        term->parse(scanner, currentToken); // Parse the first term

        // Handle addition or subtraction in expressions
        while (currentToken == ADD || currentToken == SUBTRACT) {
            simple op = currentToken; // Store the operator
            ErrorThrow::consume(scanner, currentToken, currentToken); // Consume ADD or SUBTRACT
            next = new Expression(); // Allocate memory for next Expression
            next->parse(scanner, currentToken); // Parse the next Expression
        }
    }

    ~Expression() {
        delete term; // Free memory allocated for term
        delete next; // Free memory allocated for next Expression
    }
};

// Class for handling conditions (logical expressions)
class Condition {
    Compare* comparison; // Pointer to Compare

public:
    Condition() : comparison(nullptr) {} // Initialize comparison to nullptr

    // Parse a condition
    void parse(Scanner& scanner, simple& currentToken) {
        comparison = new Compare(); // Allocate memory for Compare
        comparison->parse(scanner, currentToken); // Parse the comparison
    }

    ~Condition() {
        delete comparison; // Free memory allocated for comparison
    }
};

// Class for handling comparisons
class Compare {
    Expression* left; // Pointer to left-hand Expression
    simple op;        // Comparison operator
    Expression* right; // Pointer to right-hand Expression

public:
    Compare() : left(nullptr), right(nullptr) {} // Initialize pointers to nullptr

    // Parse a comparison expression
    void parse(Scanner& scanner, simple& currentToken) {
        left = new Expression(); // Allocate memory for left Expression
        left->parse(scanner, currentToken); // Parse left-hand expression

        // Expect a comparison operator
        if (currentToken == EQUAL || currentToken == NOTEQUAL || currentToken == LT ||
            currentToken == GT || currentToken == LTE || currentToken == GTE) {
            op = currentToken; // Store the operator
            ErrorThrow::consume(scanner, currentToken, currentToken); // Consume operator
        } else {
            cerr << "Error: Expected comparison operator, got " << ErrorThrow::tokenNames[currentToken] << endl;
            exit(1); // Exit on error
        }

        right = new Expression(); // Allocate memory for right Expression
        right->parse(scanner, currentToken); // Parse right-hand expression
    }

    ~Compare() {
        delete left; // Free memory allocated for left Expression
        delete right; // Free memory allocated for right Expression
    }
};

// Class for handling terms in expressions
class Term {
    Factor* factor; // Pointer to Factor
    Term* next;     // Pointer to next Term (for handling multiplication/division)

public:
    Term() : factor(nullptr), next(nullptr) {} // Initialize pointers to nullptr

    // Parse a term
    void parse(Scanner& scanner, simple& currentToken) {
        factor = new Factor(); // Allocate memory for Factor
        factor->parse(scanner, currentToken); // Parse the first factor

        // Handle multiplication or division in terms
        while (currentToken == MULTIPLY || currentToken == DIVIDE) {
            simple op = currentToken; // Store the operator
            ErrorThrow::consume(scanner, currentToken, currentToken); // Consume MULTIPLY or DIVIDE
            next = new Term(); // Allocate memory for next Term
            next->parse(scanner, currentToken); // Parse the next Term
        }
    }

    ~Term() {
        delete factor; // Free memory allocated for factor
        delete next; // Free memory allocated for next Term
    }
};

// Class for handling factors in expressions (numbers, variables, etc.)
class Factor {
    string name;    // Variable name (if applicable)
    double value;   // Numeric value (if applicable)
    Expression* expression; // Pointer to hold an expression in parentheses

public:
    Factor() : value(0), expression(nullptr) {} // Initialize value to 0 and expression to nullptr

    // Parse a factor
    void parse(Scanner& scanner, simple& currentToken) {
        if (currentToken == NUMBER) {
            value = scanner.getNumber(); // Store the numeric value
            ErrorThrow::consume(scanner, NUMBER, currentToken); // Consume NUMBER token
        } else if (currentToken == NAME) {
            name = scanner.getName(); // Store the variable name
            ErrorThrow::consume(scanner, NAME, currentToken); // Consume NAME token
        } else if (currentToken == LPAREN) {
            ErrorThrow::consume(scanner, LPAREN, currentToken); // Expect LPAREN token
            expression = new Expression(); // Allocate memory for Expression
            expression->parse(scanner, currentToken); // Parse inner expression
            ErrorThrow::consume(scanner, RPAREN, currentToken); // Expect RPAREN token
        } else {
            cerr << "Error: Unexpected factor token: " << ErrorThrow::tokenNames[currentToken] << endl;
            exit(1); // Exit on error
        }
    }

    ~Factor() {
        delete expression; // Free memory allocated for expression
    }
};

#endif // PARSER_H
