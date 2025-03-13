#include "defs.h"
#include "data.h"
#include "decl.h"
#include <iostream>
#include <vector>


// Returns the AST node with the current token and fetches the new token 
static ASTnode *primaryNode(void){
    ASTnode *n;

    if(Token.token == T_INT){
        n = makeASTLeafNode(A_INT,Token.intValue);
        scan(&Token);
        return n;
    }
    std::cerr << "syntax error on line " << Line << " with token-type " << Token.token ;
    exit(1);
}


static int arithOperation(int tokenType){
    switch (tokenType)
    {
    case T_PLUS:
        return A_ADD;
    case T_MINUS:
        return A_SUBSTRACT;
    case T_SLASH:
        return A_DIVIDE;
    case T_STAR:
        return A_MULTIPLY;
    default:
        std::cerr << "Unkown token in arithOperation on line" << Line ;
        exit(1);
    }
}

static std::vector<int> operationPrecedence = {0  ,10  ,10  ,20  ,20 ,   0}; 
//                                            EOF  +    -    *    /    INTLIT

static int getOperationPrecedence(int tokenType){
    int prec = operationPrecedence[tokenType];
    if(prec == 0){
        std::cerr << "Syntax Error on line " << Line << " with token-type" << tokenType << "\n";
        exit(1);
    }
    return prec;
}

ASTnode *binaryExpr(int ptp){
    ASTnode *left,*right;
    
    left = primaryNode();// gets the int literal on the left
    
    int  tokenType = Token.token; 
    //check if it's EOF or not
    if(tokenType == T_EOF){
        return left; // no tokens left
    }
   
    // While the precedence of this tokens is more 
    // than the that of previous token precedence 
    while(getOperationPrecedence(tokenType) > ptp){
       scan(&Token); // Fetch the next sub-expression's first token 
       
       right = binaryExpr(operationPrecedence[tokenType]);// Recursively call the binaryExpr 
       
       left = makeASTNode(arithOperation(tokenType),left,right,0);// Join the left and right tree to make a subtree
              
       if(Token.token ==T_EOF ){
           return left;
       }
    }
    return left;
}