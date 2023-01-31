#include <stdio.h>
#include "include/string.h"

int main(void)
{
    String *string = String_FromCharArray("Hello, there!\n");
    fprintf(stdout, StringFmt "\n", StringFmtArgs(string));
    Free_String(string);
    return 0;
}