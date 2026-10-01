#include <stdio.h>
#include <wchar.h>

#include "box.h"

int box_basename(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(
            stderr,
            L"Usage: box basename PATH\n"
        );
        return 1;
    }

    const wchar_t *path = argv[1];
    const wchar_t *end = path + wcslen(path);

    while (end > path &&
           (end[-1] == L'\\' || end[-1] == L'/')) {
        end--;
    }

    if (end == path) {
        wprintf(L"\\\n");
        return 0;
    }

    const wchar_t *start = end;

    while (start > path &&
           start[-1] != L'\\' &&
           start[-1] != L'/') {
        start--;
    }

    wprintf(
        L"%.*ls\n",
        (int)(end - start),
        start
    );

    return 0;
}
