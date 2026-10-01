#include <stdio.h>

#include "box.h"

int box_help(int argc, wchar_t **argv)
{
    (void)argc;
    (void)argv;

    wprintf(L"box - Windows toolbox\n\n");
    wprintf(L"Usage: box <command> [arguments...]\n\n");

    wprintf(L"Commands:\n");
    wprintf(L"  ls       List directory contents\n");
    wprintf(L"  cat      Print file contents\n");
    wprintf(L"  cp       Copy files\n");
    wprintf(L"  mv       Move or rename files\n");
    wprintf(L"  rm       Remove files\n");
    wprintf(L"  mkdir    Create directories\n");
    wprintf(L"  rmdir    Remove empty directories\n");
    wprintf(L"  pwd      Print current directory\n");
    wprintf(L"  touch    Create or update files\n");
    wprintf(L"  echo     Print text\n");
    wprintf(L"  whoami   Print current user\n");
    wprintf(L"  clear    Clear the console\n");
    wprintf(L"  head     Show first lines of a file\n");
    wprintf(L"  tail     Show last lines of a file\n");
    wprintf(L"  grep     Search text in a file\n");
    wprintf(L"  find     Find files and directories\n");
    wprintf(L"  which    Locate a command\n");
    wprintf(L"  basename  Get filename from path\n");
    wprintf(L"  dirname   Get directory from path\n");
    wprintf(L"  sleep    Wait for a number of seconds\n");
    wprintf(L"  date     Show current date and time\n");
    wprintf(L"  help     Show this help\n");

    return 0;
}
