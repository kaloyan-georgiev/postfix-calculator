#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Is character number
int is_number(char c){
    if(c >= '0' && c<= '9'){
        return 1;
    }
    return 0;
}

// Is character not operator
int not_operator(char c) {
    if(c != '+' && c != '-' && c != '*' && c != '/') {
        return 1;
    }
    return 0;
}

// Is character operator
int is_operator(char c){
    return !not_operator(c);    
}

int validate(char* string) {
    int num_of_operands = 0;
    int num_of_operators = 0;
    for(int i=0; string[i] != '\0'; i++) {
        // Validating operators and operands
        if(is_number(string[i])) {
            if(string[i+1] == '\n' || string[i+1] == '\0' || (string[i+1] == ' ' || is_operator(string[i+1]))){
                num_of_operands++;
            }
        }
        // 5 4 + +
        else if(is_operator(string[i])){
            if(num_of_operands >= 2){
                num_of_operators++;
            }
            else{
                printf("There should be more operands.");
                return 0;
            }
        }
        else if(string[i] == '.'){
            if(i == 0 || (!is_number(string[i-1]) || !is_number(string[i+1])) ){
                printf("Error around '.'\n");
                return 0;
            }
        }
        else if(string[i] == 'l' && string[i+1] == 'o' && string[i+2] == 'g'){
                num_of_operators++;
                i=i+2;
        }
        else if(string[i] == 'p' && string[i+1] == 'i'){
                num_of_operands++;
                i++;
        }
        else if(string[i] == 'l' && string[i+1] == 'n'){
                i++;
        }
        else if(string[i] == 'e'){
            num_of_operands++;
        }
        else if(string[i] != ' ' && string[i] != '\n'){
            printf("Character '%c' is not a valid character\n",string[i]);
            return 0;
        }

    }
    
    // Comparison between number of operands and operators
    if(num_of_operands < num_of_operators + 1){
        printf("Operators should be less.\n");
        return 0;
    }
    if(num_of_operands > num_of_operators + 1){
        printf("Operands should be less.\n");
        return 0;
    }

    
    //printf("operands:%d operators:%d\n",num_of_operands,num_of_operators);
    return 1;
}

#endif
