#include <stdio.h>
#include <stdlib.h>
#include "buffer_funcs.c"
#include "valid.c"

#define CHAR_BUF_SIZE 128
#define OPERAND_BUF_SIZE 16
#define OPERATOR_BUF_SIZE 16

void clean_buffer(char char_buffer[], int char_size, double operand_buffer[], int operand_size, int operator_buffer[][2], int operator_size);
int fill_buffer(char buffer[], int size);

int main(){
    double operand_buffer[OPERAND_BUF_SIZE];
    int operator_buffer[OPERATOR_BUF_SIZE][2];
    char buffer[CHAR_BUF_SIZE];
    int code = 0;
    int dist_code;
    int last_opn;
    int last_opr;

    printf("%s", "Enter the expression or 'S' to stop the program.\n");

    while (1){

        clean_buffer(buffer, CHAR_BUF_SIZE, operand_buffer, OPERAND_BUF_SIZE, operator_buffer, OPERATOR_BUF_SIZE);
        code = fill_buffer(buffer, CHAR_BUF_SIZE);

        if (code == -1)
            break;
        if (code == -2){
            printf("The buffer is full, the buffer size is %d characters.\n", CHAR_BUF_SIZE - 1);
            continue;
        }

        dist_code = dist(buffer, operand_buffer, operator_buffer, OPERAND_BUF_SIZE, OPERATOR_BUF_SIZE, code, &last_opn, &last_opr);
        if (dist_code == 0)
        {
            int i;
            for (i = 0; i < OPERAND_BUF_SIZE; ++i)
                printf("%f ", operand_buffer[i]);
            printf("\n");
            for (i = 0; i < OPERATOR_BUF_SIZE; ++i)
                printf("%c ", (operator_buffer[i])[0]);
            printf("\n");            
        }
        else if (dist_code == -1){
            printf("Bad expression.\n");
            continue;
        }
        else if (dist_code == -2){
            printf("The operator buffer is full, the buffer size is %d characters.\n", OPERATOR_BUF_SIZE - 1);
            continue;
        }
        else if (dist_code == -3){
            printf("The operand is full, the buffer size is %d characters.\n", OPERAND_BUF_SIZE - 1);
            continue;
        }
        
    } 
    return 0 ;
}