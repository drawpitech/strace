/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** strace
*/

#pragma once

#include <sys/types.h>
#include <sys/user.h>

#define LENGTH(x) (sizeof(x) / sizeof *(x))

enum {
    RET_VALID = 0,
    RET_ERROR = 84
};

typedef struct {
    struct user_regs_struct regs;
    pid_t pid;
} strace_t;

int strace(int argc, char **argv, char **env);
void display_syscall(strace_t *strace);
