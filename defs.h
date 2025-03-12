#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



enum {
    T_PLUS,T_MINUS,T_STAR,T_SLASH,T_INT
};

typedef struct {
    int token;
    int intValue;
} token;