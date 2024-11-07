#include <stdlib.h>
#include <stdio.h>

void reverse(char* buffer, int length) 
{
    int start;
    int end;
    char temp;

	start = 0;
	end = length - 1;
    while (start < end) {
        temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
}

int handle_negative(int *value, int base) {
    if (*value < 0 && base == 10) {
        *value = -*value;
        return 1;
    }
    return 0;
}

int get_length(int value, int base) 
{
    int length;

	length = 0;
    if (value == 0)
	{
        return 1;
    }
    while (value != 0)
	{
        length++;
        value = value / base;
    }
    return length;
}

char* ft_itoa(int value, int base) {
    int i = 0;
    int isNegative;
    int length;
    char* buffer;

	isNegative = handle_negative(&value, base);
	length = get_length(value, base);
	buffer = malloc((length + 1 + isNegative) * sizeof(char));
    if (value == 0)
	{
        buffer[i++] = '0';
        buffer[i] = '\0';
        return buffer;
    }
    while (value != 0) {
        int remainder;
		remainder = value % base;
        if (remainder > 9)
            buffer[i++] = remainder - 10 + 'a';
        else
            buffer[i++] = remainder + '0';
        value = value / base;
    }
    if (isNegative) {
        buffer[i++] = '-';
    }
    buffer[i] = '\0';
    reverse(buffer, i);
    return buffer;
}

