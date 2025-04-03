# Notes

## Basics of Compiler's Job
![alt text](images/parsing_steps.png)

  - Do lexical analysis to recongnise the lexical elements .
  - Grammar Analysis - recognise the syntax of input and ensure that they follow the grammar of the language. 
  - Semantic Analysis - undertand the meaning of input
  - Translate the input to a different language

## BNF - Backus-Naur Form
  - Notation system for defining the syntax of programming languages
  - Example
    ```
      expression: number
                | expression '*' expression
                ;
      number:  T_INTLIT
                ; 
    ```

## Parse Tree vs Abstract Syntax tree 
  - Parse tree are tree that represents the syntatic sturcture of input is called the Parse Tree and the 
  - Abstract syntax tree show us the significant pieces of an expression / the abstracted syntax of text.
  - Todo-> Add a diagram showing the complete process 


## Operator Precedence 

  ### Method 1 - Making the operator precedence explicit in language's grammar
    
  - Here is a example of normal grammer.
    
      ```
      expression: number
          | expression '*' expression
          | expression '/' expression
          | expression '+' expression
          | expression '-' expression
          ;
    
      number:  T_INTLIT
              ;
      ```
    
    You can add the Operator Precedence directly to the grammar
    
      ```
      expression: additive_expression
          ;
      
      additive_expression:
            multiplicative_expression
          | additive_expression '+' multiplicative_expression
          | additive_expression '-' multiplicative_expression
          ;
      
      multiplicative_expression:
            number
          | number '*' multiplicative_expression
          | number '/' multiplicative_expression
          ;
      
      number:  T_INTLIT
              ;
      ```
    The above way of constructing recursive a recursive parser will eb inefficient, so instead of this we will choose a different method
    
  ### Method 2 - Pratt Parsing (can be wrong)
  - In Pratt Parser , each token knows how to parse itself by having two functions
      - Null Denotation(nud): This is used when a token apperas at beginning of an 
        expression. eg a no returns its value or a minus sign might indicate a unary negation 
      - Left Denotation(led): This is used when a token apperars after another expression
        eg. + operator combines left expression and the right expression
  - A Pratt Parser has a single recursive function that reads the token, uses `nud` functions
  to get value,if an operator with high enough precedence appears, calls `led` function to combine the expression.
  - The `right-binding-power(rbp)` is essentialy a threshold.The parser will continue to call itself recursively if the 
  `rbp` of current token / operator is higher than the previous `rbp` .
     