#include "defs.h"

int scan(token *t); 
ASTnode *makeASTNode(int operation,ASTnode *left,ASTnode *right,int intValue);
ASTnode *makeASTLeafNode(int operation,int intValue);
ASTnode *makeASTSingleChildNode(int operation,ASTnode *left,int intValue);
ASTnode *binaryExpr(int ptp);
int interpretAST(ASTnode *n);