#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_rm(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(stderr, L"Usage: box rm FILE\n");
        return 1;
    }

    if (!DeleteFileW(argv[1])) {
        fwprintf(
            stderr,
            L"box rm: failed to remove '%ls'\n",
            argv[1]
        );
        return 1;
    }

    return 0;
}