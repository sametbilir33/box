#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_cp(int argc, wchar_t **argv)
{
    if (argc != 3) {
        fwprintf(stderr, L"Usage: box cp SOURCE DEST\n");
        return 1;
    }

    if (!CopyFileW(argv[1], argv[2], FALSE)) {
        fwprintf(
            stderr,
            L"box cp: failed to copy '%ls'\n",
            argv[1]
        );
        return 1;
    }

    return 0;
}