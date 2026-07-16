#include <stdio.h>
#define BUF_SIZE 16

void clean_buffer(char buffer[], int size);
int fill_buffer(char buffer[], int size);

int main(){
    char buffer[BUF_SIZE];
    int code = 0;
    int dbg_i;

    printf("%s", "Enter the expression or 'S' to stop the program.\n");

    while (1){

        clean_buffer(buffer, BUF_SIZE);
        code = fill_buffer(buffer, BUF_SIZE);

        if (code == -1)
            break;
        if (code == -2){
            printf("%s%d %s", "The buffer is full, the buffer size is ", BUF_SIZE - 1, "characters.");
            continue;
        }

        printf("%s\n", buffer);
    } 
}