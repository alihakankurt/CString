#include "include/string.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

String * String_FromCharArray(const char *array)
{
    assert(array && "String_FromCharArray(const char *): Could not create string 'cause provided array was null");
    String *string = malloc(sizeof(String));
    assert(string && "String_FromCharArray(const char *): Could not allocate enough memory for string object");
    int length = strlen(array);
    string->length = length;
    int size = length * sizeof(char);
    string->start = malloc(size);
    if (!string)
    {
        free(string);
        assert("String_FromCharArray(const char *): Could not allocate enough memory for string object");
    }
    memcpy(string->start, array, size);
    return string;
}

void Free_String(String *string)
{
    assert(string && string->start && "Free_String(String *): Could not release memory of string object 'cause it was null");
    free(string->start);
    free(string);
}

String * String_Concat(String *self, int count, ...)
{
    assert(self && "String_Concat(String *,int,...): Could not concatanate strings 'cause self was null");
    va_list args;
    va_start(args, count);
    String *other;
    while (count--)
    {
        other = va_arg(args, String*);
        self->start = realloc(self->start, (self->length + other->length) * sizeof(char));
        assert(self->start && "String_Concat(String *,int,...): Could not allocate enough memory for string object");
        memcpy(self->start + self->length, other->start, other->length * sizeof(char));
        self->length += other->length;
    }
    return self;
}
