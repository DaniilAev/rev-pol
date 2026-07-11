void clean_buffer(char buffer[], int size){
       int position;
       for (position = 0; position < size; ++position)
           buffer[position] = '\0';
}