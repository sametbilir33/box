#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <wchar.h>

#include "box.h"

static void print_size(ULONGLONG size, int human)
{
    if (!human) {
        wprintf(L"%10llu", size);
        return;
    }

    const wchar_t *units[] = {
        L"B", L"K", L"M", L"G", L"T"
    };

    double value = (double)size;
    int unit = 0;

    while (value >= 1024.0 && unit < 4) {
        value /= 1024.0;
        unit++;
    }

    if (unit == 0)
        wprintf(L"%4lluB", size);
    else
        wprintf(L"%6.1f%c", value, units[unit][0]);
}

static void print_time(const FILETIME *file_time)
{
    FILETIME local_time;
    SYSTEMTIME system_time;

    if (!FileTimeToLocalFileTime(file_time, &local_time) ||
        !FileTimeToSystemTime(&local_time, &system_time)) {
        wprintf(L"----/--/-- --:--");
        return;
    }

    wprintf(
        L"%04d-%02d-%02d %02d:%02d",
        system_time.wYear,
        system_time.wMonth,
        system_time.wDay,
        system_time.wHour,
        system_time.wMinute
    );
}

int box_ls(int argc, wchar_t **argv)
{
    int show_all = 0;
    int long_format = 0;
    int human_size = 0;

    const wchar_t *path = L".";

    for (int i = 1; i < argc; i++) {

        if (wcscmp(argv[i], L"-a") == 0)
            show_all = 1;

        else if (wcscmp(argv[i], L"-l") == 0)
            long_format = 1;

        else if (wcscmp(argv[i], L"-h") == 0)
            human_size = 1;

        else if (wcscmp(argv[i], L"-la") == 0 ||
                 wcscmp(argv[i], L"-al") == 0) {
            show_all = 1;
            long_format = 1;
        }

        else if (wcscmp(argv[i], L"-lh") == 0 ||
                 wcscmp(argv[i], L"-hl") == 0) {
            long_format = 1;
            human_size = 1;
        }

        else if (wcscmp(argv[i], L"-lah") == 0 ||
                 wcscmp(argv[i], L"-lha") == 0 ||
                 wcscmp(argv[i], L"-alh") == 0 ||
                 wcscmp(argv[i], L"-ahl") == 0 ||
                 wcscmp(argv[i], L"-hal") == 0 ||
                 wcscmp(argv[i], L"-hla") == 0) {
            show_all = 1;
            long_format = 1;
            human_size = 1;
        }

        else if (argv[i][0] == L'-') {
            fwprintf(
                stderr,
                L"box ls: unknown option: %ls\n",
                argv[i]
            );
            return 1;
        }

        else {
            path = argv[i];
        }
    }

    wchar_t pattern[MAX_PATH];

    if (swprintf(
            pattern,
            MAX_PATH,
            L"%ls\\*",
            path
        ) < 0) {

        fwprintf(
            stderr,
            L"box ls: path too long\n"
        );

        return 1;
    }

    WIN32_FIND_DATAW data;

    HANDLE handle = FindFirstFileW(
        pattern,
        &data
    );

    if (handle == INVALID_HANDLE_VALUE) {
        fwprintf(
            stderr,
            L"box ls: cannot access '%ls'\n",
            path
        );

        return 1;
    }

    do {
        const wchar_t *name = data.cFileName;

        if (!show_all && name[0] == L'.')
            continue;

        if (long_format) {

            ULONGLONG size =
                ((ULONGLONG)data.nFileSizeHigh << 32) |
                data.nFileSizeLow;

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                wprintf(L"DIR  ");
            else
                wprintf(L"FILE ");

            print_size(
                size,
                human_size
            );

            wprintf(L"  ");

            print_time(
                &data.ftLastWriteTime
            );

            wprintf(
                L"  %ls\n",
                name
            );
        }
        else {
            wprintf(
                L"%ls\n",
                name
            );
        }

    } while (FindNextFileW(handle, &data));

    FindClose(handle);

    return 0;
}