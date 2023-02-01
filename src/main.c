#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *a = STR("Hello, there!");
    Str *b = Str_Clone(a);
    fprintf(stdout, StrFmt "\n", StrFmtArgsA(b, 2));
    fprintf(stdout, StrFmt "\n", StrFmtArgsEx(b, 2, 4));
    DEL_STR(a);
    DEL_STR(b);
    return 0;
}