#include "include/string.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

String * String_FromCharArray(const char *array)
{
    assert(array && "Could not create string 'cause provided array was null");
    String *string = malloc(sizeof(String));
    assert(string && "Could not allocate enough memory for string object");
    int length = strlen(array);
    string->length = length;
    int size = length * sizeof(char);
    string->start = malloc(size);
    if (!string)
    {
        free(string);
        assert("Could not allocate enough memory for string object");
    }
    memcpy(string->start, array, size);
    return string;
}

unsigned char Free_String(String *string)
{
    if (!string || !string->start)
        return 0;
    free(string->start);
    free(string);
    return 1;
}
