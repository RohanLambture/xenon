#include "defs.h"
#include "data.h"
#include "decl.h"
#include <iostream>

// Returns the next character from the input file
static int next(void){
    int c;

    if(PutBack){
        //std::cout << "There was a putback" << std::endl;
        c = PutBack;
        PutBack = 0;
        return c;
    }
    //std::cout << "Here " << std::endl;
    c=fgetc(InFile);  //Read a single charcter and returns the ascii code of character
    
    //std:: cout <<"got the character " << std::endl;

    if('\n' == c){ //end of the line 
        Line++; 
    }
    return c;
}

static void putback(int c){
    PutBack = c;
}

static int scanInt(int c){
    int value = 0;

    while(isdigit(c)){
        value = value *10 + (c-'0');
        c = next();
    }

    //at the end of while, we get a non-int value ,so put it back
    putback(c);
    return value;
}




// Returns the first character that we need 
// i.e skips the whitespace ,newlines etc
static int getChar(void){
    //std::cout << "Getting the character " << std::endl;
    int c;
    c = next();
    
    //std:: cout << "got the charcter in getChar function" << std::endl;
    while(' '== c || '\t'==c || '\r'==c || '\f'==c || '\n' == c){
        c = next();
    }
    return c;
}

//scans the Token from input and puts it in the Global Token variable
int scan(token *t){
    int c;

    c = getChar();

    switch (c)
    {
    case EOF:
        t->token = T_EOF;
        return 0;
    case '+':
        t->token = T_PLUS;
        break;
    case '-':
        t->token = T_MINUS;
        break;
    case '*':
        t->token = T_STAR;
        break;
    case '/':
        t->token = T_SLASH;
        break;
    default:    
        // if it's digit
        if(isdigit(c)){
            t->intValue = scanInt(c);
            t->token = T_INT;
            break;
        }

        std::cerr << "Unrecongnise charcter " << c << " on the line " << Line << "\n";
        exit(1);

    }
    return 1; // found a token 

}