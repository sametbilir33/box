#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <wchar.h>

#include "box.h"

static void find_recursive(
    const wchar_t *directory,
    const wchar_t *name
)
{
    wchar_t pattern[MAX_PATH];

    if (swprintf(
            pattern,
            MAX_PATH,
            L"%ls\\*",
            directory
        ) < 0) {
        return;
    }

    WIN32_FIND_DATAW data;

    HANDLE handle = FindFirstFileW(
        pattern,
        &data
    );

    if (handle == INVALID_HANDLE_VALUE)
        return;

    do {
        const wchar_t *entry = data.cFileName;

        if (wcscmp(entry, L".") == 0 ||
            wcscmp(entry, L"..") == 0)
            continue;

        wchar_t path[MAX_PATH];

        if (swprintf(
                path,
                MAX_PATH,
                L"%ls\\%ls",
                directory,
                entry
            ) < 0) {
            continue;
        }

        if (wcscmp(name, L"*") == 0 ||
            wcscmp(entry, name) == 0) {
            wprintf(L"%ls\n", path);
        }

        if (data.dwFileAttributes &
            FILE_ATTRIBUTE_DIRECTORY) {

            find_recursive(
                path,
                name
            );
        }

    } while (FindNextFileW(handle, &data));

    FindClose(handle);
}

int box_find(int argc, wchar_t **argv)
{
    if (argc < 2) {
        fwprintf(
            stderr,
            L"Usage: box find PATH -name NAME\n"
        );
        return 1;
    }

    const wchar_t *path = argv[1];
    const wchar_t *name = L"*";

    for (int i = 2; i < argc; i++) {
        if (wcscmp(argv[i], L"-name") == 0) {
            if (i + 1 >= argc) {
                fwprintf(
                    stderr,
                    L"box find: missing name\n"
                );
                return 1;
            }

            name = argv[i + 1];
            i++;
        }
        else {
            fwprintf(
                stderr,
                L"box find: unknown option: %ls\n",
                argv[i]
            );
            return 1;
        }
    }

    find_recursive(
        path,
        name
    );

    return 0;
}
