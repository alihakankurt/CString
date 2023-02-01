#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *a = STR("Hello,");
    Str *b = STR("there!");
    fprintf(stdout, "%d\n", Str_Compare(a, b));
    DEL_STR(a);
    DEL_STR(b);
    return 0;
}