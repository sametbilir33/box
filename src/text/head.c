#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "box.h"

int box_head(int argc, wchar_t **argv)
{
    int lines = 10;
    int file_index = 1;

    if (argc > 1 && wcscmp(argv[1], L"-n") == 0) {
        if (argc < 3) {
            fwprintf(stderr, L"box head: missing line count\n");
            return 1;
        }

        lines = _wtoi(argv[2]);

        if (lines < 0) {
            fwprintf(stderr, L"box head: invalid line count\n");
            return 1;
        }

        file_index = 3;
    }

    if (argc <= file_index) {
        fwprintf(stderr, L"Usage: box head [-n N] FILE\n");
        return 1;
    }

    FILE *file = _wfopen(
        argv[file_index],
        L"r, ccs=UTF-8"
    );

    if (!file) {
        fwprintf(
            stderr,
            L"box head: cannot open '%ls'\n",
            argv[file_index]
        );
        return 1;
    }

    wchar_t buffer[8192];

    for (int i = 0; i < lines; i++) {
        if (!fgetws(buffer, 8192, file))
            break;

        wprintf(L"%ls", buffer);
    }

    fclose(file);

    return 0;
}
