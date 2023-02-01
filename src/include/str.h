#ifndef __STR_H__
#define __STR_H__

#define STR(str) Str_FromConst(str)
#define DEL_STR(str) Str_Free(str)
#define StrFmt "%.*s"
#define StrFmtArgs(str) str->length, str->start

typedef struct Str
{
    int length;
    char *start;
} Str;

Str * Str_FromConst(const char *constant);
void Str_Free(Str *self);
Str * Str_Concat(Str *self, int count, ...);
Str * Str_Extend(Str *self, const char *constant);
int Str_Compare(Str *self, Str *other);

#endif