#define BUF_SIZE 8192

void clean_buffer(char buffer[], int size);

int main(){
    char buffer[BUF_SIZE];
    int code = 0;
    
    while (code != 0){
        clean_buffer(buffer, BUF_SIZE);
        
        } 
}