#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_date(int argc, wchar_t **argv)
{
    (void)argc;
    (void)argv;

    SYSTEMTIME time;

    GetLocalTime(&time);

    wprintf(
        L"%04d-%02d-%02d %02d:%02d:%02d\n",
        time.wYear,
        time.wMonth,
        time.wDay,
        time.wHour,
        time.wMinute,
        time.wSecond
    );

    return 0;
}
