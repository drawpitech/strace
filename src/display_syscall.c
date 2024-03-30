#include <stdio.h>

#include "strace.h"
#include "syscall.h"

static void display_return(strace_t *strace, const syscall_t *syscall) {
    size_t id = strace->regs.orig_rax;

    printf(") = ");
    // exit && exit_group
    if (id == 60 || id == 231) {
        printf("?\n+++ exited with %lld +++\n", strace->regs.rdi);
        return;
    }
    if (syscall->ret_type == VOID) {
        printf("?\n");
        return;
    }
    printf("%lld\n", strace->regs.rax);
}

void display_syscall(strace_t *strace)
{
    unsigned long id = strace->regs.orig_rax;
    const syscall_t *syscall = NULL;

    if (id > LENGTH(SYSCALLS))
        return;
    syscall = &SYSCALLS[id];
    printf("%s(", syscall->name);
    display_return(strace, syscall);
}
