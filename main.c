#include <stdio.h>
#include <stdlib.h>
#include "unit.c"
#include "valid.c"
#include "buffer_funcs.c"

#define CHAR_BUF_SIZE 128
#define UNIT_BUF_SIZE 16

void clean_buffer(char char_buffer[], struct unit unit_buffer[], int char_size, int unit_size);
int fill_buffer(char buffer[], int size);

int main(){
    struct unit unit_buffer[UNIT_BUF_SIZE];
    char buffer[CHAR_BUF_SIZE];
    int code = 0;
    int dist_code;

    printf("Enter the expression or 'S' to stop the program.\n");

    while (1){

        clean_buffer(buffer, unit_buffer, CHAR_BUF_SIZE, UNIT_BUF_SIZE);
        code = fill_buffer(buffer, CHAR_BUF_SIZE);

        if (code == -1)
            break;
        if (code == -2){
            printf("The buffer is full, the buffer size is %d characters.\n", CHAR_BUF_SIZE - 1);
            continue;
        }

        dist_code = dist(unit_buffer, buffer, UNIT_BUF_SIZE, code);
        if (dist_code == 0)
        {
            int i;
            for (i = 0; i < UNIT_BUF_SIZE; ++i){
                 switch (unit_buffer[i].type){
                     case '1':
                         printf("%c ", (char)unit_buffer[i].unit_field.operr);
                         break;
                     case '2':
                         printf("%.2f ", unit_buffer[i].unit_field.operd);
                         break;
                     case 0:
                         printf("STOP ");  
                         goto done;
                     }
            }
            done:
            printf("\n");
        }
        else if (dist_code == -1){
            printf("Bad expression.\n");
            continue;
        }
        else if (dist_code == -2){
            printf("The operator buffer is full, the buffer size is %d operands and operators.\n", UNIT_BUF_SIZE - 1);
            continue;
        }
        
    } 
    return 0 ;
}