#include "include/str.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

Str * Str_FromConst(const char *constant)
{
    assert(constant && "Str_FromConst(const char*): Could not create str object 'cause provided constant was null");
    Str *str = malloc(sizeof(Str));
    assert(str && "Str_FromConst(const char*): Could not allocate enough memory for str object");
    int length = strlen(constant);
    str->length = length;
    int size = length * sizeof(char);
    str->start = malloc(size);
    if (!str)
    {
        free(str);
        assert("Str_FromConst(const char*): Could not allocate enough memory for str object");
    }
    memcpy(str->start, constant, size);
    return str;
}

void Str_Free(Str *self)
{
    assert(self && self->start && "Str_Free(Str*): Could not release memory of `self` 'cause it was null");
    free(self->start);
    free(self);
}

Str * Str_Concat(Str *self, int count, ...)
{
    assert(self && "Str_Concat(Str*,int,...): Could not concatanate 'cause `self` was null");
    va_list args;
    va_start(args, count);
    Str *other;
    while (count--)
    {
        other = va_arg(args, Str *);
        if (!other) continue;
        self->start = realloc(self->start, (self->length + other->length) * sizeof(char));
        assert(self->start && "Str_Concat(Str*,int,...): Could not reallocate enough memory for `self`");
        memcpy(self->start + self->length, other->start, other->length * sizeof(char));
        self->length += other->length;
    }
    return self;
}

Str * Str_Extend(Str *self, const char *constant)
{
    assert(self && "Str_Extend(Str*,const char*): Could not extend the `self` 'cause it was null");
    assert(constant && "Str_Extend(Str*,const char*): Could not extend the `self` 'cause constant was null");
    int length = strlen(constant);
    self->start = realloc(self->start, (self->length + length) * sizeof(char));
    assert(self->start && "Str_Extend(Str*,const char*): Could not reallocate enough memory for `self`");
    memcpy(self->start + self->length, constant, length * sizeof(char));
    self->length += length;
    return self;
}
