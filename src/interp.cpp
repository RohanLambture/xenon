#include "../headers/defs.h"
#include "../headers/data.h"
#include "../headers/interp.h"

#include <iostream>


int interpretAST(ASTnode *n){
	int leftValue,rightValue;

	if(n->left){
		leftValue = interpretAST(n->left);
	}
	if(n->right){
		rightValue = interpretAST(n->right);
	}

	switch (n->operation)
	{
	case A_ADD:
		return leftValue+rightValue;
	case A_DIVIDE:
		return leftValue/rightValue;
	case A_MULTIPLY:
		return leftValue*rightValue;
	case A_SUBSTRACT:
		return leftValue-rightValue;
	case A_INT: 
		return n->intValue;    
	default:
		std::cerr << ":Unknown AST Operation on line " << Line  << '\n';
		exit(1);
	}
}
