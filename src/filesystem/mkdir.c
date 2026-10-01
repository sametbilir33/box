#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_mkdir(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(stderr, L"Usage: box mkdir DIRECTORY\n");
        return 1;
    }

    if (!CreateDirectoryW(argv[1], NULL)) {
        fwprintf(
            stderr,
            L"box mkdir: failed to create '%ls'\n",
            argv[1]
        );
        return 1;
    }

    return 0;
}