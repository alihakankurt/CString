#include <stdio.h>
#include "include/str.h"

int main(void)
{
    Str *str = STR("Hello, there!");
    Span *span = SPAN(str, 7, 12);
    FOREACH_STR(c, str)
    {
        fprintf(stdout, "%c", c);
    }
    fprintf(stdout, "\n");
    FOREACH_SPAN(c, span)
    {
        fprintf(stdout, "%c", c);
    }
    DEL_SPAN(span);
    DEL_STR(str);
    return 0;
}