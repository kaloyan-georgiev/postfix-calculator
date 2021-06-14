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
            if(string[i+1] != '\0' && string[i+1] == ' '){
                num_of_operands++;
            }
        }
        else if(!not_operator(string[i])){
            num_of_operators++;
        }
        else if(string[i] == '.'){
            if(i == 0 || (!is_number(string[i-1]) || !is_number(string[i+1])) ){
                return 0;
            }
        }
        else if(string[i] == 'l' && string[i+1] == 'o' && string[i+2] == 'g'){
            if(string[i+1] == '\0' || string[i+2] == '\0'){
                return 0;
            }
            else{
                num_of_operators++;
                i=i+2;
            }
        }
        else if(string[i] == 'p' && string[i+1] == 'i'){
            if(string[i+1] == '\0'){
                return 0;
            }
            else{
                num_of_operands++;
                i++;
            }
        }
        else if(string[i] == 'l' && string[i+1] == 'n'){
            if(string[i+1] == '\0'){
                return 0;
            }
            else{
                i++;
            }
        }
        else if(string[i] == 'e'){
            num_of_operands++;
        }
        else if(string[i] != ' '){
            printf("%c \n",string[i]);
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

int main () {
    
    printf("%d", validate("213 3 1 ln + +"));
    return 0;
    
}
