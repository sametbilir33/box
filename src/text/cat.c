#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_cat(int argc, wchar_t **argv)
{
    if (argc < 2) {
        fwprintf(stderr, L"box cat: missing file\n");
        return 1;
    }

    HANDLE file = CreateFileW(
        argv[1],
        GENERIC_READ,
        FILE_SHARE_READ |
        FILE_SHARE_WRITE |
        FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (file == INVALID_HANDLE_VALUE) {
        fwprintf(
            stderr,
            L"box cat: cannot open '%ls'\n",
            argv[1]
        );
        return 1;
    }

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    if (output == INVALID_HANDLE_VALUE || output == NULL) {
        CloseHandle(file);
        return 1;
    }

    char buffer[8192];
    DWORD bytes_read;

    while (ReadFile(
        file,
        buffer,
        sizeof(buffer),
        &bytes_read,
        NULL
    )) {
        if (bytes_read == 0)
            break;

        DWORD total_written = 0;

        while (total_written < bytes_read) {

            DWORD written;

            if (!WriteFile(
                output,
                buffer + total_written,
                bytes_read - total_written,
                &written,
                NULL
            )) {
                CloseHandle(file);
                return 1;
            }

            total_written += written;
        }
    }

    CloseHandle(file);

    return 0;
}