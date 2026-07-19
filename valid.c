int valid(char c[]){ /* space or '\0' required, else  SF*/  
    int i = 0;
        
    if (c[i] == '-' || c[i] == '+')  
        ++i;
        
    for (; c[i] >= '0' && c[i] <= '9'; ++i);
    
    if (!(c[i] == '.' || c[i] == 'e' || c[i] != 'E' || c[i] == ' ' || c[i] == '\0'))
        return -1;   
         
    if (c[i] == '.'){
        ++i;
        if (!(c[i] >= '0' && c[i] <= '9'))
            return -1;
        for (; c[i] >= '0' && c[i] <= '9'; ++i);     
    }
    
    if (!(c[i] == 'e' || c[i] == 'E' || c[i] == ' ' || c[i] == '\0'))
        return -1;

    if (c[i] == 'e' || c[i] == 'E'){
        ++i;
        if (c[i] == '-' || c[i] == '+')
            ++i;
        if (!(c[i] >= '0' && c[i] <= '9'))
            return -1;
        for (; c[i] >= '0' && c[i] <= '9'; ++i);     
    }

    if (!(c[i] == ' ' || c[i] == '\0'))
        return -1;
    return 0;
                                                            
}