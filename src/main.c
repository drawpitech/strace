#include <linux/limits.h>
#include <linux/ptrace.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "strace.h"

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

static int child(char **argv, char **env)
{
    char buf[PATH_MAX] = {0};

    if (getpath(buf, argv[0]) == NULL)
        return RET_ERROR;
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    execve(argv[0], argv, env);
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

int main(int argc, char **argv, char **env)
{
    pid_t pid = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return RET_ERROR;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return RET_ERROR;
    }

    if (pid == 0)
        return child(argv + 1, env);
    return parent(pid);
}
