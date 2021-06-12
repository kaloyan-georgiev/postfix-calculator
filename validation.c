#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//to do :
// last operation is with 1 number in stack

int not_letter(char* c){
    char pi[] = "pi";
    char ln[] = "ln";
    char log[] = "log";
    if((strcmp(c,pi) == 0) && (strcmp(c,ln) == 0) && (strcmp(c,log)==0)){
        return 1;
    }
    return 0;
}
int not_operator(char c) {
    if(c != '+' && c != '-' && c != '*' && c != '/' && c != 'e') {
        return 1;
    }
    return 0;
}
int validate(char* string) {
    int num_of_operands = 0;
    int num_of_operators = 0;
    for(int i=0; string[i] != '\0'; i++) {
        // Validating operators and operands
        if((string[i] < '0' || string[i] > '9') && not_operator(string[i]) && string[i] != ' ' && not_letter(&string[i])) {
            printf("%c\n", string[i]);
            printf("Not valid operator/operand");
            return 0;
        }

        // Getting number of operands and operators
        if(not_letter(&string[i]) || not_operator(string[i]) && string[i] != ' '){
            num_of_operands++;
        }
        else if(not_letter(&string[i])==1 || not_operator(string[i])==0){
            num_of_operators++;
        }
    }
    // Comparison between number of operands and operators
    if(num_of_operands < num_of_operators + 1){
        printf("Operators should be less");
        return 0;
    }
    // Kalata i Dankata kato si napravqt funkciqta
    if(num_of_operands != 1){
       printf("There should be only one number in stack.");
    }
    printf("%d %d\n",num_of_operands,num_of_operators);
    return 1;
}

int main () {
    printf("%d", validate("5 4 3 * +"));
    return 0;
}
