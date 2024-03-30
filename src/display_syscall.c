/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** display_syscall
*/

#include <stdio.h>

#include "strace.h"
#include "syscall.h"

static const size_t EXECVE_ID = 59;
static const size_t EXIT_ID = 60;
static const size_t EXIT_GROUP_ID = 231;

static void display_return(strace_t *strace, const syscall_t *syscall)
{
    size_t id = strace->regs.orig_rax;

    printf(") = ");
    if (id == EXIT_ID || id == EXIT_GROUP_ID) {
        printf("?\n+++ exited with %lld +++\n", strace->regs.rdi);
        return;
    }
    if (syscall->ret_type == VOID) {
        printf("?\n");
        return;
    }
    printf("0x%llx\n", strace->regs.rax);
}

static void display_args(strace_t *strace, const syscall_t *syscall)
{
    unsigned long long args[6] = {
        strace->regs.rdi, strace->regs.rsi, strace->regs.rdx,
        strace->regs.rcx, strace->regs.r8, strace->regs.r9,
    };

    if (strace->regs.orig_rax == EXECVE_ID) {
        printf("\"%s\", [\"%s\"], 0x%llx /* %d vars */",
            strace->filename, strace->filename, strace->regs.rdx, 0);
        return;
    }
    for (size_t i = 0; i < 6 && syscall->args[i] != 0; i++) {
        if (i != 0)
            printf(", ");
        printf("0x%llx", args[i]);
    }
}

void display_syscall(strace_t *strace)
{
    unsigned long id = strace->regs.orig_rax;
    const syscall_t *syscall = NULL;

    if (id > LENGTH(SYSCALLS))
        return;
    syscall = &SYSCALLS[id];
    printf("%s(", syscall->name);
    display_args(strace, syscall);
    display_return(strace, syscall);
}
