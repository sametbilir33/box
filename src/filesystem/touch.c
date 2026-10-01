#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_touch(int argc, wchar_t **argv)
{
    if (argc < 2) {
        fwprintf(stderr, L"Usage: box touch FILE...\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        HANDLE handle = CreateFileW(
            argv[i],
            FILE_WRITE_ATTRIBUTES,
            FILE_SHARE_READ |
            FILE_SHARE_WRITE |
            FILE_SHARE_DELETE,
            NULL,
            OPEN_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL
        );

        if (handle == INVALID_HANDLE_VALUE) {
            fwprintf(
                stderr,
                L"box touch: failed to create '%ls'\n",
                argv[i]
            );
            return 1;
        }

        FILETIME now;

        GetSystemTimeAsFileTime(&now);

        if (!SetFileTime(
                handle,
                NULL,
                NULL,
                &now
            )) {

            fwprintf(
                stderr,
                L"box touch: failed to update '%ls'\n",
                argv[i]
            );

            CloseHandle(handle);
            return 1;
        }

        CloseHandle(handle);
    }

    return 0;
}