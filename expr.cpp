#include "defs.h"
#include "data.h"
#include "decl.h"
#include <iostream>

static ASTnode *primaryNode(void){
    ASTnode *n;

    if(Token.token == T_INT){
        n = makeASTLeafNode(A_INT,Token.intValue);
        return n;
    }
    return NULL;
}


static int arithOperation(){
    switch (Token.token)
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



ASTnode *binaryExpr(void){
    ASTnode *left;
    left = primaryNode();
    if(left == NULL){
        std::cerr << "Syntax Error on line " << Line << '\n';
    }
    scan(&Token);
    //check if it's EOF or not
    if(Token.token == T_EOF){
        return left;
    }

    //If it's not EOF then it is a arithmatic operation 
    int nodeOperation= arithOperation();
    
    scan(&Token);

    ASTnode *right = binaryExpr();

    return makeASTNode(nodeOperation,left,right,0);

}