#include <stdio.h>
#include <stdlib.h>

int valid(const char s[]);

void clean_buffer(char char_buffer[], int char_size, double operand_buffer[], int operand_size, char operator_buffer[], int operator_size){
       int position;

       for (position = 0; position < char_size; ++position)
           char_buffer[position] = '\0';
        for (position = 0; position < operand_size; ++position)
            operand_buffer[position] = 0.0;
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

int dist(const char ch_buffer[], double opn_buffer[], char opr_buffer[], int opn_buffer_size, int opr_buffer_size, int code){
    int ch_car = 0;
    int opn_car = 0;
    int opr_car = 0;

    while (ch_car < code)
    {
        if (opr_car == opr_buffer_size - 1)
            return -2;
        if (ch_buffer[ch_car] == '\0')
            return 0;
        else if (ch_buffer[ch_car] == ' '){ /*Space case*/
            ++ch_car;
            continue;
        }
        else if (ch_buffer[ch_car] == '+' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /*Plus case*/
            opr_buffer[opr_car++] = '+';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '-' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Minus case*/
            opr_buffer[opr_car++] = '-';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '*' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Mult case*/
            opr_buffer[opr_car++] = '*';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '/' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Div case*/
            opr_buffer[opr_car++] = '/';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '%' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* MOD case*/
            opr_buffer[opr_car++] = '%';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '^' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Power case*/
            opr_buffer[opr_car++] = '^';
            ch_car += 2;
            continue;
        }    
        else{
            if (valid(&ch_buffer[ch_car]) == 0){
                if (opn_car == opn_buffer_size -1)
                    return -3;

                opn_buffer[opn_car++] = atof(&ch_buffer[ch_car]);

                while (!(ch_buffer[ch_car] == ' ' || ch_buffer[ch_car] == '\0'))
                    ++ch_car;              
            } 
            else
                return -1;
        }        
    }
    return 0;
    
}