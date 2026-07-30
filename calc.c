#include <math.h>
#ifndef val
    #include "valid.c"
#endif
#ifndef uni
    #include "unit.c"
#endif

int calc(struct unit Buffer[], double * result_poi){
    int i;
    int j;
    struct unit *left_operand;
    struct unit *right_operand;
    double result;
    
    if (Buffer[0].type != 2)
        return -1;

    result = Buffer[0].unit_field.operd;

    for (i = 0; Buffer[i].type != 0; ++i){
        if (Buffer[i].type == 1){

            /*Right operand search*/
            for (j = i - 1; j >= 0; --j){
                if (Buffer[j].type == 2){
                    right_operand = &Buffer[j];
                    goto right_found;
                }
            }
            return -1;
            right_found:

            /*Left operand search*/
            --j;
            for (;j >= 0; --j){
                if (Buffer[j].type == 2){
                    left_operand = &Buffer[j];
                    goto left_found;
                }
            }
            return -1;
            left_found:

            switch (Buffer[i].unit_field.operr)
            {
            case '+':
                result = (Buffer[i].unit_field.operd = left_operand->unit_field.operd + right_operand->unit_field.operd);
                Buffer[i].type = 2;
                break;
            case '-':
                result = (Buffer[i].unit_field.operd = left_operand->unit_field.operd - right_operand->unit_field.operd);
                Buffer[i].type = 2;
                break;
            case '*':
                result = (Buffer[i].unit_field.operd = left_operand->unit_field.operd * right_operand->unit_field.operd);
                Buffer[i].type = 2;     
                break;  
            case '/':
                if (right_operand->unit_field.operd == 0.0)
                    return -2;
                result = (Buffer[i].unit_field.operd = left_operand->unit_field.operd / right_operand->unit_field.operd);
                Buffer[i].type = 2;
                break;
            case '^':
                result = (Buffer[i].unit_field.operd = pow(left_operand->unit_field.operd, right_operand->unit_field.operd));
                Buffer[i].type = 2;
                break;
            }

            left_operand->type = 3;
            right_operand->type = 3;
        }
    }

    /*Result checking*/
    for (j = 0; j < i - 1; ++j){
        if (Buffer[j].type < 3)
            return -1;
    }

    /*Result returning*/
    *result_poi = result;
    return 0;
}