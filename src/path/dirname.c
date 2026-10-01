#include <stdio.h>
#include <wchar.h>

#include "box.h"

int box_dirname(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(
            stderr,
            L"Usage: box dirname PATH\n"
        );
        return 1;
    }

    const wchar_t *path = argv[1];
    size_t length = wcslen(path);

    while (length > 0 &&
           (path[length - 1] == L'\\' ||
            path[length - 1] == L'/')) {
        length--;
    }

    if (length == 0) {
        wprintf(L".\n");
        return 0;
    }

    const wchar_t *separator = NULL;

    for (size_t i = 0; i < length; i++) {
        if (path[i] == L'\\' || path[i] == L'/')
            separator = &path[i];
    }

    if (!separator) {
        wprintf(L".\n");
        return 0;
    }

    if (separator == path) {
        wprintf(L"\\\n");
        return 0;
    }

    wprintf(
        L"%.*ls\n",
        (int)(separator - path),
        path
    );

    return 0;
}
