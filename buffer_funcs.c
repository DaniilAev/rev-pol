#include <stdio.h>

void clean_buffer(char char_buffer[], int char_size, double operand_buffer[], int operand_size, char operator_buffer[], int operator_size){
       int position;
       for (position = 0; position < char_size; ++position)
           char_buffer[position] = '\0';
        for (position = 0; position < operand_size; ++position)
            operand_buffer[position] = 0;
        for (position = 0; position < operator_size; ++position)
            operator_buffer[position] = '\0';
}

int fill_buffer(char buffer[], int size){
    int position;
    int ch;

    for (position = 0; position < size; ++position){
        ch = getchar();
        if (position == 0 && ch == 'S')
            return -1;
        if (ch == EOF || ch == '\n')
            goto valid;
        buffer[position] = ch;  
    }
    
    while ((ch = getchar()) != EOF && ch != '\n');
    return -2;

    valid:
    return position;
}