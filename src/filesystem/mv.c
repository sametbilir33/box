#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_mv(int argc, wchar_t **argv)
{
    if (argc != 3) {
        fwprintf(stderr, L"Usage: box mv SOURCE DEST\n");
        return 1;
    }

    if (!MoveFileW(argv[1], argv[2])) {
        fwprintf(
            stderr,
            L"box mv: failed to move '%ls'\n",
            argv[1]
        );
        return 1;
    }

    return 0;
}