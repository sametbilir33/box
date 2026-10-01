#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_which(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(
            stderr,
            L"Usage: box which COMMAND\n"
        );
        return 1;
    }

    wchar_t path[MAX_PATH];

    DWORD length = SearchPathW(
        NULL,
        argv[1],
        NULL,
        MAX_PATH,
        path,
        NULL
    );

    if (length == 0) {
        fwprintf(
            stderr,
            L"box which: command not found: %ls\n",
            argv[1]
        );
        return 1;
    }

    wprintf(L"%ls\n", path);

    return 0;
}
