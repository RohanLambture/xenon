#include "headers/data.h"
#include "headers/defs.h"
#include "headers/scanner.h"
#include "headers/expr.h"
#include "headers/interp.h"
#include <iostream>


int Line;
int PutBack;
FILE *InFile;
token Token;

// Initialise global variables 
static void init(){
    Line = 1;
    PutBack = 0;
}

int main(int argc,char *argv[]){
    ASTnode *n;

    if(argc!=2){
        std::cerr << "Wrong Usage!!\n";
        exit(1); 
    }
    init();

    // std::ifstream InFile;
    // InFile.open(argv[1]);

    InFile = fopen(argv[1],"r");
    if(!InFile){
        std::cerr << "Unable to open " << argv[1]  <<"\n";
        exit(1);
    }

    scan(&Token);
    n = binaryExpr(0);
    int calculation = interpretAST(n);

    std::cout << calculation <<" is the answer of the input \n";
    fclose(InFile);
    exit(0);
    
}