int strLen(char* str)     
{ 
    return *str == '\0' ? 0 : 1 + strLen( str + 1 );
} 