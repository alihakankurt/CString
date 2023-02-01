#ifndef __STR_H__
#define __STR_H__

#define STR(str) Str_FromConst(str)
#define DEL_STR(str) Str_Free(str)
#define StrFmt "%.*s"
#define StrFmtLn "%.*s\n"
#define StrFmtArgs(str) str->length, str->start
#define StrFmtArgsA(str, ofst) str->length - ofst, str->start + ofst
#define StrFmtArgsEx(str, ofst, len) len, str->start + ofst
#define FOREACH_STR(c, str) for (int c = *(str->start), index_##c = 0; index_##c <= str->length; c = *(str->start + ++index_##c))
#define STR_AT(str, i) *(str->start + i)

typedef struct Str
{
    int length;
    char *start;
} Str;

Str * Str_FromConst(const char *constant);
void Str_Free(Str *self);
Str * Str_Concat(Str *self, int count, ...);
Str * Str_Extend(Str *self, const char *constant);
Str * Str_Shrink(Str *self, int length);
Str * Str_ShrinkStart(Str *self, int length);
int Str_Compare(Str *self, Str *other);
Str * Str_Clone(Str *self);

#define SPAN(str, s, e) Span_FromStr(str, s, e)
#define DEL_SPAN(span) Span_Free(span)
#define SpanStrFmtArgs(span) span->end - span->start, span->str->start + span->start
#define FOREACH_SPAN(c, span) for (int c = *(str->start + span->start), index_##c = span->start; index_##c <= span->end; c = *(str->start + ++index_##c))
#define SPAN_AT(span, i) *(span->str->start + span->start + i)

typedef struct Span
{
    int start;
    int end;
    Str *str;
} Span;

Span * Span_FromStr(Str *str, int start, int end);
void Span_Free(Span *self);

#endif