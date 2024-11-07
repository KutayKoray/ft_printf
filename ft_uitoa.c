#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char* ft_uitoa(unsigned long value, int base) 
{
    int i = 0;
    int length;
    char* buffer;

    length = get_length(value, base);  
    buffer = malloc((length + 1) * sizeof(char));
    if (value == 0) 
	{
        buffer[i++] = '0';
        buffer[i] = '\0';
        return buffer;
    }
    while (value != 0) 
	{
        int remainder = value % base;
        if (remainder > 9)
            buffer[i++] = remainder - 10 + 'a';
        else
            buffer[i++] = remainder + '0';
        value = value / base;
    }
    buffer[i] = '\0';
    reverse(buffer, i);
    return buffer;
}
