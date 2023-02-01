#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *hello = STR("Hello,");
    Str_Extend(hello, " there!");
    fprintf(stdout, StrFmt "\n", StrFmtArgs(hello));
    Str_Free(hello);
    return 0;
}