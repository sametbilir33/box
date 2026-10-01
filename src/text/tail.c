#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "box.h"

int box_tail(int argc, wchar_t **argv)
{
    int lines = 10;
    int file_index = 1;

    if (argc > 1 && wcscmp(argv[1], L"-n") == 0) {
        if (argc < 3) {
            fwprintf(stderr, L"box tail: missing line count\n");
            return 1;
        }

        lines = _wtoi(argv[2]);

        if (lines < 0) {
            fwprintf(stderr, L"box tail: invalid line count\n");
            return 1;
        }

        file_index = 3;
    }

    if (argc <= file_index) {
        fwprintf(stderr, L"Usage: box tail [-n N] FILE\n");
        return 1;
    }

    FILE *file = _wfopen(
        argv[file_index],
        L"r, ccs=UTF-8"
    );

    if (!file) {
        fwprintf(
            stderr,
            L"box tail: cannot open '%ls'\n",
            argv[file_index]
        );
        return 1;
    }

    if (lines == 0) {
        fclose(file);
        return 0;
    }

    wchar_t **buffer = calloc(
        (size_t)lines,
        sizeof(wchar_t *)
    );

    if (!buffer) {
        fclose(file);
        fwprintf(stderr, L"box tail: out of memory\n");
        return 1;
    }

    wchar_t line[8192];
    int count = 0;

    while (fgetws(line, 8192, file)) {

        wchar_t *copy = _wcsdup(line);

        if (!copy) {
            for (int i = 0; i < lines; i++)
                free(buffer[i]);

            free(buffer);
            fclose(file);

            fwprintf(stderr, L"box tail: out of memory\n");
            return 1;
        }

        free(buffer[count % lines]);

        buffer[count % lines] = copy;
        count++;
    }

    int start = count > lines ? count - lines : 0;

    for (int i = start; i < count; i++) {
        wprintf(
            L"%ls",
            buffer[i % lines]
        );
    }

    for (int i = 0; i < lines; i++)
        free(buffer[i]);

    free(buffer);
    fclose(file);

    return 0;
}
