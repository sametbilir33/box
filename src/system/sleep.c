#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "box.h"

int box_sleep(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(
            stderr,
            L"Usage: box sleep SECONDS\n"
        );
        return 1;
    }

    wchar_t *end;

    double seconds = wcstod(
        argv[1],
        &end
    );

    if (end == argv[1] ||
        *end != L'\0' ||
        seconds < 0) {
        fwprintf(
            stderr,
            L"box sleep: invalid duration\n"
        );
        return 1;
    }

    DWORD milliseconds;

    if (seconds > 4294967.0) {
        fwprintf(
            stderr,
            L"box sleep: duration too large\n"
        );
        return 1;
    }

    milliseconds = (DWORD)(seconds * 1000.0);

    Sleep(milliseconds);

    return 0;
}
