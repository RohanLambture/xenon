#include "defs.h"
#pragma once

ASTnode *makeASTNode(int operation,ASTnode *left,ASTnode *right,int intValue);
ASTnode *makeASTLeafNode(int operation,int intValue);
ASTnode *makeASTSingleChildNode(int operation,ASTnode *left,int intValue);