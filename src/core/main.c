#include <stdio.h>
#include <wchar.h>

#include "box.h"

int wmain(int argc, wchar_t **argv)
{
    if (argc < 2)
        return box_help(argc, argv);

    if (wcscmp(argv[1], L"ls") == 0)
        return box_ls(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"cat") == 0)
        return box_cat(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"cp") == 0)
        return box_cp(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"mv") == 0)
        return box_mv(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"rm") == 0)
        return box_rm(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"mkdir") == 0)
        return box_mkdir(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"pwd") == 0)
        return box_pwd(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"touch") == 0)
        return box_touch(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"rmdir") == 0)
        return box_rmdir(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"echo") == 0)
        return box_echo(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"whoami") == 0)
        return box_whoami(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"clear") == 0)
        return box_clear(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"head") == 0)
        return box_head(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"tail") == 0)
        return box_tail(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"grep") == 0)
        return box_grep(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"find") == 0)
        return box_find(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"which") == 0)
        return box_which(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"basename") == 0)
        return box_basename(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"dirname") == 0)
        return box_dirname(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"sleep") == 0)
        return box_sleep(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"date") == 0)
        return box_date(argc - 1, argv + 1);

    if (wcscmp(argv[1], L"help") == 0)
        return box_help(argc - 1, argv + 1);

    fwprintf(
        stderr,
        L"box: unknown command: %ls\n",
        argv[1]
    );

    fwprintf(
        stderr,
        L"Try 'box help'.\n"
    );

    return 1;
}
