#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_pwd(int argc, wchar_t **argv)
{
    (void)argc;
    (void)argv;

    wchar_t path[MAX_PATH];

    DWORD length = GetCurrentDirectoryW(
        MAX_PATH,
        path
    );

    if (length == 0) {
        fwprintf(
            stderr,
            L"box pwd: failed to get current directory\n"
        );
        return 1;
    }

    if (length >= MAX_PATH) {
        fwprintf(
            stderr,
            L"box pwd: path is too long\n"
        );
        return 1;
    }

    wprintf(L"%ls\n", path);

    return 0;
}