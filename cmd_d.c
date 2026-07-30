#ifndef val
    #include "valid.c"
#endif
#ifndef uni
    #include "unit.c"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmd_dist(int argc, char* argv[], struct unit unit_buffer[], int unit_size){
    int i = 0; 
    int j;
    for (j = 1; j < argc; ++j){
        if (i == unit_size - 1)
            return -2;
        else if (argv[j][0] == '+' && argv[j][1] == '\0'){
            unit_buffer[i].type = 1;
            unit_buffer[i++].unit_field.operr = '+'; 
            continue;
        }
        else if (argv[j][0] == '-' && argv[j][1] == '\0'){
            unit_buffer[i].type = 1;
            unit_buffer[i++].unit_field.operr = '-'; 
            continue;
        }
        else if (argv[j][0] == '*' && argv[j][1] == '\0'){
            unit_buffer[i].type = 1;
            unit_buffer[i++].unit_field.operr = '*'; 
            continue;
        }
        else if (argv[j][0] == '/' && argv[j][1] == '\0'){
            unit_buffer[i].type = 1;
            unit_buffer[i++].unit_field.operr = '/'; 
            continue;
        }
        else if (argv[j][0] == '^' && argv[j][1] == '\0'){
            unit_buffer[i].type = 1;
            unit_buffer[i++].unit_field.operr = '^'; 
            continue;
        }
        else{
            if (valid(argv[j]) == 0){                
                unit_buffer[i].type = 2;
                unit_buffer[i++].unit_field.operd = atof(argv[j]);
                continue;
            }
        }
    }
    return 0;
}