#ifndef BOX_H
#define BOX_H

#include <wchar.h>

int box_ls(int argc, wchar_t **argv);
int box_cat(int argc, wchar_t **argv);
int box_cp(int argc, wchar_t **argv);
int box_mv(int argc, wchar_t **argv);
int box_rm(int argc, wchar_t **argv);
int box_mkdir(int argc, wchar_t **argv);
int box_help(int argc, wchar_t **argv);

int box_pwd(int argc, wchar_t **argv);
int box_touch(int argc, wchar_t **argv);
int box_rmdir(int argc, wchar_t **argv);
int box_echo(int argc, wchar_t **argv);
int box_whoami(int argc, wchar_t **argv);

int box_clear(int argc, wchar_t **argv);
int box_head(int argc, wchar_t **argv);
int box_tail(int argc, wchar_t **argv);
int box_grep(int argc, wchar_t **argv);
int box_find(int argc, wchar_t **argv);
int box_which(int argc, wchar_t **argv);
int box_basename(int argc, wchar_t **argv);
int box_dirname(int argc, wchar_t **argv);
int box_sleep(int argc, wchar_t **argv);
int box_date(int argc, wchar_t **argv);

#endif
