#include <stdio.h>
#include <stdlib.h>
int valid(const char s[]);

void clean_buffer(char char_buffer[], struct unit unit_buffer[], int char_size, int unit_size){
       int position;

       for (position = 0; position < char_size; ++position)
           char_buffer[position] = '\0';
       for (position = 0; position < unit_size; ++position){
           unit_buffer[position].type = 0;
           unit_buffer[position].unit_field.operd = 0;           
       }

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

int dist(struct unit unit_buffer[], char ch_buffer[], int unit_size, int code){
    int ch_car = 0;
    int unit_car = 0;

    while (ch_car < code)
    {
        if (unit_car == unit_size - 1)
            return -2;
        if (ch_buffer[ch_car] == '\0')
            return 0;
        else if (ch_buffer[ch_car] == ' '){ /*Space case*/
            ++ch_car;
            continue;
        }
        else if (ch_buffer[ch_car] == '+' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /*Plus case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car].unit_field.operr = '+';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '-' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Minus case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car++].unit_field.operr = '-';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '*' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Mult case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car++].unit_field.operr = '*';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '/' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Div case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car++].unit_field.operr = '/';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '%' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* MOD case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car++].unit_field.operr = '%';
            ch_car += 2;
            continue;
        }
        else if (ch_buffer[ch_car] == '^' && (ch_buffer[ch_car+1] == ' ' || ch_buffer[ch_car+1] == '\0')){ /* Power case*/
            unit_buffer[unit_car].type = '1';
            unit_buffer[unit_car++].unit_field.operr = '^';
            ch_car += 2;
            continue;
        }    
        else{
            if (valid(&ch_buffer[ch_car]) == 0){
                unit_buffer[unit_car].type = '2';
                unit_buffer[unit_car++].unit_field.operd = atof(&ch_buffer[ch_car]);

                while (!(ch_buffer[ch_car] == ' ' || ch_buffer[ch_car] == '\0'))
                    ++ch_car;              
            } 
            else
                return -1;
        }        
    }
    return 0;
    
}