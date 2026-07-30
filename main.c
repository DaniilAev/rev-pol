#include <stdio.h>
#include <stdlib.h>
#include "unit.c"
#include "valid.c"
#include "buffer_funcs.c"
#include "calc.c"
#include "cmd_d.c"

#define CHAR_BUF_SIZE 2048
#define UNIT_BUF_SIZE 512

void clean_buffer(char char_buffer[], struct unit unit_buffer[], int char_size, int unit_size);
int fill_buffer(char buffer[], int size);
int cmd_dist(int argc, char* argv[], struct unit unit_buffer[], int unit_size);

int main(int argc, char* argv[]){
    struct unit unit_buffer[UNIT_BUF_SIZE];
    char buffer[CHAR_BUF_SIZE];
    int code = 0;
    int dist_code;
    int calc_code;
    int cmd_code;
    double result;
    int i;
    if (argc <2){
        printf("Enter the expression, or S for stop the programm.\n");
    }
    else{
        clean_buffer(buffer, unit_buffer, CHAR_BUF_SIZE, UNIT_BUF_SIZE);

        cmd_code = cmd_dist(argc, argv, unit_buffer, UNIT_BUF_SIZE);
    
        if (cmd_code == -2){
            printf("The operator buffer is full, the buffer size is %d operands and operators.\n", UNIT_BUF_SIZE - 1);
            return 1;
        }
        if (cmd_code == -1){
            printf("Bad expression.\n");
            return 1;
        }
        calc_code = calc(unit_buffer, &result);
        if (calc_code == -1){
            printf("Bad expression.\n");
            return 1;
        }
        if (calc_code == -2){
            printf("Zero division.\n");
            return 1;
        }
        printf("Result: %f\n", result);
        return 0;
    }
    
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
            calc_code = calc(unit_buffer, &result);
            if (calc_code == -1){
                printf("Bad expression.\n");
                continue;
            }
            if (calc_code == -2){
                printf("Zero division.\n");
                continue;
            }
            printf("Result: %f\n", result);
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