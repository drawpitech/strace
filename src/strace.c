/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** strace
*/

#include "strace.h"

#include <linux/limits.h>
#include <linux/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#include "args.h"

static char *getpath(char *buf, const char *filename)
{
    if (filename[0] == '/') {
        strcpy(buf, filename);
        return buf;
    }
    if (getcwd(buf, PATH_MAX) == NULL) {
        perror("getcwd");
        return NULL;
    }
    strcat(buf, "/");
    strcat(buf, filename);
    return buf;
}

static int make_me_a_child(char *filename)
{
    char buf[PATH_MAX] = {0};
    char *argv[2] = {filename, NULL};

    if (getpath(buf, argv[0]) == NULL)
        return RET_ERROR;
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    execvp(filename, argv);
    perror("execve");
    return RET_ERROR;
}

static int calling_your_parent(strace_t *strace)
{
    int status = 0;

    waitpid(strace->pid, &status, 0);
    if (WIFEXITED(status))
        return RET_VALID;
    if (ptrace(PTRACE_SETOPTIONS, strace->pid, 0, PTRACE_O_TRACEEXIT) == -1)
        return RET_ERROR;
    while (!WIFEXITED(status)) {
        if (ptrace(PTRACE_GETREGS, strace->pid, 0, &strace->regs) == -1)
            return RET_ERROR;
        display_syscall(strace);
        if (ptrace(PTRACE_SINGLESTEP, strace->pid, 0, 0) == -1)
            return RET_ERROR;
        waitpid(strace->pid, &status, 0);
    }
    return RET_VALID;
}

static int fork_me_hard(char *filename, strace_t *strace)
{
    strace->pid = fork();
    if (strace->pid == -1) {
        perror("fork");
        return RET_ERROR;
    }
    if (strace->pid == 0)
        return make_me_a_child(filename);
    return RET_VALID;
}

static int follow_me_home(pid_t pid)
{
    if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) {
        perror("ptrace");
        return RET_ERROR;
    }
    return RET_VALID;
}

int my_strace(int argc, char **argv)
{
    strace_t strace = {0};

    get_args(argc, argv, &strace);
    if (strace.filename == NULL && strace.pid == 0) {
        fprintf(stderr, "Invalid arguments\n");
        return RET_ERROR;
    }
    if (strace.flag & PID) {
        if (follow_me_home(strace.pid) == RET_ERROR)
            return RET_ERROR;
    } else {
        if (fork_me_hard(strace.filename, &strace) == RET_ERROR)
            return RET_ERROR;
    }
    return calling_your_parent(&strace);
}
