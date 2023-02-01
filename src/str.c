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
    size_t size = length * sizeof(char);
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

int Str_Compare(Str *self, Str *other)
{
    assert(self && "Str_Compare(Str*,Str*): Could not compare 'cause `self` was null");
    assert(other && "Str_Compare(Str*,Str*): Could not compare 'cause `other` was null");
    if (self->length < other->length)
        return -1;
    if (self->length > other->length)
        return 1;
    int diff = 0, len = self->length, offset = 0;
    while (len >= 8)
    {
        diff += *((long long *)(self->start + offset)) - *((long long *)(other->start + offset));
        offset += 8;
        len -= 8;
    }
    while (len >= 4)
    {
        diff += *((int *)(self->start + offset)) - *((int *)(other->start + offset));
        offset += 4;
        len -= 4;
    }
    while (len >= 1)
    {
        diff += *(self->start + offset) - *(other->start + offset);
        offset += 1;
        len -= 1;
    }
    return diff ? (diff < 0 ? -1 : 1) : 0;
}

Str * Str_Clone(Str *self)
{
    assert(self && "Str_Clone(Str*): Could not clone `self` 'cause it was null");
    Str *clone = malloc(sizeof(Str));
    assert(clone && "Str_Clone(Str*): Could not allocate enough memory for `clone`");
    clone->length = self->length;
    size_t size = clone->length * sizeof(char);
    clone->start = malloc(size);
    if (!clone->start)
    {
        free(clone);
        assert("Str_Clone(Str*): Could not allocate enough memory for `clone`");
    }
    memcpy(clone->start, self->start, size);
    return clone;
}
