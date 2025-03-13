#include "defs.h"
#include "decl.h"


ASTnode *makeASTNode(int operation,ASTnode *left,ASTnode *right,int intValue){
    ASTnode *n = new ASTnode;
    n->operation = operation;
    n->left = left;
    n->right = right;
    n->intValue = intValue;
    return n;
}



ASTnode *makeASTLeafNode(int operation,int intValue){
    return makeASTNode(operation,NULL,NULL,intValue);
}

ASTnode *makeASTSingleChildNode(int operation,ASTnode *left,int intValue){
    return makeASTNode(operation,left,NULL,intValue);
}