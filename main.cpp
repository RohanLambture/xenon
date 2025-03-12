#include "defs.h"
#include "data.h"
#include "decl.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int Line;
int PutBack;
FILE *InFile;


// Initialise global variables 
static void init(){
    Line = 1;
    PutBack = 0;
}

// List of tokens 
std::vector<std::string> tokenStr = {"+","-","*","/","int"};


static void readfile(){
    //std::cout << "Reading the file " << std::endl;
    token t;

    while(scan(&t)){
        std::cout << "Token Type:" << tokenStr[t.token];
        if(t.token == T_INT){
            std::cout << "IntValue :" << t.intValue;
        }
        std::cout << '\n';
    }
    //std::cout << "End of the reading of the file " << std::endl;
    
}


int main(int argc,char *argv[]){
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
    }

    readfile();
    fclose(InFile);
    exit(0);
}