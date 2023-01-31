#include <stdio.h>
#include "include/string.h"

int main(void)
{
    String *hello = String_FromCharArray("Hello,");
    String *there = String_FromCharArray(" there!");
    String_Concat(hello, 1, there);
    fprintf(stdout, StringFmt "\n", StringFmtArgs(hello));
    Free_String(hello);
    Free_String(there);
    return 0;
}