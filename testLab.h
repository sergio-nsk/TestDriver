#ifndef labreporter
#define labreporter
#include <stddef.h>

struct labFeedAndCheck {int (*feeder)(void), (*checker)(void);};

extern const struct labFeedAndCheck labTests[];
extern const int labNTests;
extern const char labName[];
extern int labTimeout;
extern size_t labOutOfMemory;

#ifdef _WIN32
// Helpers for Windows
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#define LONG_LONG_MODIFIER "I64"
#else
// Helpers and compatibility for Linux
#define LONG_LONG_MODIFIER "ll"
#define strnicmp(a, b, c) strncasecmp((a), (b), (c))
#include <sys/time.h>
typedef unsigned int DWORD;
static DWORD GetTickCount(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return(tv.tv_sec*1000+tv.tv_sec/1000);
}
#endif /* _WIN32 */

static unsigned int tickDifference(unsigned int start, unsigned int finish)
{
    return finish-start;
}
#endif /* labreporter */
