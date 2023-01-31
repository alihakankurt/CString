#ifndef __STRING_H__
#define __STRING_H__

#define StringFmt "%.*s"
#define StringFmtArgs(string) string->length, string->start

typedef struct String
{
    int length;
    char *start;
} String;

String * String_FromCharArray(const char *array);
void Free_String(String *string);
String * String_Concat(String *self, int count, ...);

#endif