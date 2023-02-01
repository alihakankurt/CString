#ifndef __STR_H__
#define __STR_H__

#define STR(str) Str_FromConst(str)
#define DEL_STR(str) Str_Free(str)
#define StrFmt "%.*s"
#define StrFmtArgs(str) str->length, str->start
#define StrFmtArgsA(str, ofst) str->length - ofst, str->start + ofst
#define StrFmtArgsEx(str, ofst, len) len, str->start + ofst

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
Str * Str_Clone(Str *self);

#define SPAN(str, s, e) Span_FromStr(str, s, e)
#define DEL_SPAN(span) Span_Free(span)
#define SpanStrFmtArgs(span) span->end - span->start, span->str->start + span->start

typedef struct Span
{
    int start;
    int end;
    Str *str;
} Span;

Span * Span_FromStr(Str *str, int start, int end);
void Span_Free(Span *self);

#endif