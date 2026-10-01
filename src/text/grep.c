#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <wchar.h>

#include "box.h"

int box_grep(int argc, wchar_t **argv)
{
    if (argc != 3) {
        fwprintf(
            stderr,
            L"Usage: box grep PATTERN FILE\n"
        );
        return 1;
    }

    FILE *file = _wfopen(
        argv[2],
        L"r, ccs=UTF-8"
    );

    if (!file) {
        fwprintf(
            stderr,
            L"box grep: cannot open '%ls'\n",
            argv[2]
        );
        return 1;
    }

    wchar_t line[8192];
    int found = 0;

    while (fgetws(line, 8192, file)) {
        if (wcsstr(line, argv[1]) != NULL) {
            wprintf(L"%ls", line);
            found = 1;
        }
    }

    fclose(file);

    return found ? 0 : 1;
}
