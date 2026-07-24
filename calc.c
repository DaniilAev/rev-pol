#include "unit.c"

int calc(struct unit Buffer[], double * result){
    int i;
    int j;
    double left_operand;
    double right_operand;
    for (i = 0; Buffer[i].type != 0; ++i){
        if (Buffer[i].type == '1'){
            for (j = i - 1; j >= 0; --j){
                if (Buffer[j].type == '1'){
                    right_operand = Buffer[j].unit_field.operd;
                    goto right_found;
                }
            }
            return -1;
            right_found:
            --j;
            for (j = i - 1; j >= 0; --j){
                if (Buffer[j].type == '1'){
                    left_operand = Buffer[j].unit_field.operd;
                    goto left_found;
                }
            }
            return -1;
            left_found:         
        }
    }
}