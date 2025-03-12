#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



// Token types
enum {
    T_EOF,T_PLUS,T_MINUS,T_STAR,T_SLASH,T_INT
};

// Token structure
typedef struct {
    int token;      // Token type from the enum list above
    int intValue;   // For T_INT
} token;

// AST node types
enum {
    A_ADD,A_SUBSTRACT,A_MULTIPLY,A_DIVIDE,A_INT
};

// AST structure
typedef struct ASTnode{
    int operation;  //Operation to be peformed on this Tree
    struct ASTnode *left;  //left and right child trees
    struct ASTnode *right;
    int intValue;   // For A_INT 
}ASTnode;