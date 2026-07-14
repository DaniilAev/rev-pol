#include <stdio.h>

void clean_buffer(char buffer[], int size){
       int position;
       for (position = 0; position < size; ++position)
           buffer[position] = '\0';
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