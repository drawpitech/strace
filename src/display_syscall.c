/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** display_syscall
*/

#include <aio.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>

#include "args.h"
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

static void display_string(strace_t *strace, unsigned long long arg)
{
    ptrdiff_t ptr = 0;

    printf("\"");
    for (;; arg += sizeof arg) {
        ptr = ptrace(PTRACE_PEEKDATA, strace->pid, arg, 0);
        if ((long long)ptr == -1)
            break;
        printf("%.*s", (int)(sizeof ptr), (char *)&ptr);
        if (memchr(&ptr, '\0', sizeof ptr) != NULL)
            break;
    }
    printf("\"");
}

static void display_arg(
    strace_t *strace, unsigned long long arg, enum arg_type type)
{
    if (!(strace->flag & FULL)) {
        printf("0x%llx", arg);
        return;
    }
    if (type == STRING) {
        display_string(strace, arg);
        return;
    }
    printf("%lld", arg);
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
        display_arg(strace, args[i], syscall->args[i]);
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
