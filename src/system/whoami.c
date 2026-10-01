#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

#include "box.h"

int box_whoami(int argc, wchar_t **argv)
{
    (void)argc;
    (void)argv;

    wchar_t username[256];
    DWORD size = sizeof(username) / sizeof(username[0]);

    if (!GetUserNameW(username, &size)) {
        fwprintf(
            stderr,
            L"box whoami: failed to get username\n"
        );
        return 1;
    }

    wprintf(L"%ls\n", username);

    return 0;
}