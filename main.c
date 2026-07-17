#include <stdio.h>
#include "buffer_funcs.c"

#define CHAR_BUF_SIZE 16
#define OPERAND_BUF_SIZE 16
#define OPERATOR_BUF_SIZE 16

void clean_buffer(char char_buffer[], int char_size, double operand_buffer[], int operand_size, char operator_buffer[], int operator_size);
int fill_buffer(char buffer[], int size);

int main(){
    double operand_buffer[OPERAND_BUF_SIZE];
    char operator_buffer[OPERATOR_BUF_SIZE];
    char buffer[CHAR_BUF_SIZE];
    int code = 0;

    printf("%s", "Enter the expression or 'S' to stop the program.\n");

    while (1){

        clean_buffer(buffer, CHAR_BUF_SIZE, operand_buffer, OPERAND_BUF_SIZE, operator_buffer, OPERATOR_BUF_SIZE);
        code = fill_buffer(buffer, CHAR_BUF_SIZE);

        if (code == -1)
            break;
        if (code == -2){
            printf("%s%d %s", "The buffer is full, the buffer size is ", BUF_SIZE - 1, "characters.");
            continue;
        }

        printf("%s\n", buffer);
    } 
    return 0 ;
}