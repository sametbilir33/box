#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

static int write_utf8(const wchar_t *text)
{
    int length = WideCharToMultiByte(
        CP_UTF8,
        0,
        text,
        -1,
        NULL,
        0,
        NULL,
        NULL
    );

    if (length <= 0)
        return 1;

    char buffer[length];

    if (WideCharToMultiByte(
            CP_UTF8,
            0,
            text,
            -1,
            buffer,
            length,
            NULL,
            NULL
        ) <= 0) {
        return 1;
    }

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    if (output == INVALID_HANDLE_VALUE || output == NULL)
        return 1;

    DWORD written;

    if (!WriteFile(
            output,
            buffer,
            (DWORD)(length - 1),
            &written,
            NULL
        )) {
        return 1;
    }

    return 0;
}

int box_echo(int argc, wchar_t **argv)
{
    for (int i = 1; i < argc; i++) {

        if (i > 1) {
            if (write_utf8(L" ") != 0)
                return 1;
        }

        if (write_utf8(argv[i]) != 0)
            return 1;
    }

    return write_utf8(L"\n");
}