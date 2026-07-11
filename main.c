#include <stdio.h>
#define BUF_SIZE 16

void clean_buffer(char buffer[], int size);
int fill_buffer(char buffer[], int size);

int main(){
    char buffer[BUF_SIZE];
    int code = 0;
    while (code != -1){
        clean_buffer(buffer, BUF_SIZE);
        code = fill_buffer(buffer, BUF_SIZE);
        if (code == -2){
            printf("%s", "Buffer is overflowing, but symbol of ending of exspression not detected.\n");
            continue;
        }
        printf("%s\n", buffer);
    } 
}