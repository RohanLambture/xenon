#include "headers/data.h"
#include "headers/defs.h"
#include "headers/scanner.h"
#include "headers/expr.h"
#include "headers/interp.h"
#include <cstdio>
#include <iostream>


int Line;
int PutBack;
FILE *InFile;
token Token;
FILE *OutFile;


// Initialise global variables 
static void init(){
	Line = 1;
	PutBack = 0;
}

int main(int argc,char *argv[]){
	ASTnode *n;

	if(argc!=3){
		std::cerr << "Wrong Usage!!\n";
		std::cerr << "./parser inputfile outputfile";
		exit(1); 
	}
	init();


	InFile = fopen(argv[1],"r");
	if(!InFile){
		std::cerr << "Unable to open " << argv[1]  <<"\n";
		exit(1);
	}
	
	OutFile = fopen(argv[2],"w");
	if(!OutFile){
		std::cerr << "Unable to open " <<argv[2] << "\n";
	}

	scan(&Token);
	n = binaryExpr(0);
	int calculation = interpretAST(n);

	std::cout << calculation <<" is the answer of the input \n";
	fclose(InFile);
	exit(0);
}
