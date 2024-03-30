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

static int child(char *filename)
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

static int parent(pid_t pid)
{
    int status = 0;
    strace_t strace = {0};

    strace.pid = pid;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return RET_VALID;
    if (ptrace(PTRACE_SETOPTIONS, strace.pid, 0, PTRACE_O_TRACEEXIT) == -1)
        return RET_ERROR;
    while (!WIFEXITED(status)) {
        if (ptrace(PTRACE_GETREGS, pid, 0, &strace.regs) == -1)
            return RET_ERROR;
        display_syscall(&strace);
        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
            return RET_ERROR;
        waitpid(pid, &status, 0);
    }
    return RET_VALID;
}

int strace(int argc, char **argv)
{
    args_t flags = {0};
    pid_t pid = 0;

    get_args(argc, argv, &flags);
    if (flags.filename == NULL && flags.pid == 0) {
        fprintf(stderr, "Invalid arguments\n");
        return RET_ERROR;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return RET_ERROR;
    }
    if (pid == 0)
        return child(flags.filename);
    return parent(pid);
}
