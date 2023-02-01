#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *s = STR("Hello, there!");
    Span *sp = SPAN(s, 7, 12);
    fprintf(stdout, StrFmt "\n", SpanStrFmtArgs(sp));
    DEL_STR(s);
    DEL_SPAN(sp);
    return 0;
}