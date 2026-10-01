#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "box.h"

int box_clear(int argc, wchar_t **argv)
{
    (void)argc;
    (void)argv;

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    if (output == INVALID_HANDLE_VALUE || output == NULL)
        return 1;

    CONSOLE_SCREEN_BUFFER_INFO info;

    if (!GetConsoleScreenBufferInfo(output, &info))
        return 1;

    DWORD cells =
        (DWORD)info.dwSize.X *
        (DWORD)info.dwSize.Y;

    COORD home = { 0, 0 };
    DWORD written;

    FillConsoleOutputCharacterW(
        output,
        L' ',
        cells,
        home,
        &written
    );

    FillConsoleOutputAttribute(
        output,
        info.wAttributes,
        cells,
        home,
        &written
    );

    SetConsoleCursorPosition(output, home);

    return 0;
}
