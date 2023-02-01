#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *str = STR("Hello, there!");
    Str_Shrink(str, 1);
    Str_ShrinkStart(str, 1);
    fprintf(stdout, StrFmtLn, StrFmtArgs(str));
    DEL_STR(str);
    return 0;
}