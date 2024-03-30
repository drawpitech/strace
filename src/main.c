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

enum
{
    RET_VALID = 0,
    RET_ERROR = 84
};

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
    /* wait4(pid, NULL, 0, NULL); */
    /* while (ptrace(PTRACE_SYSCALL, pid, 0, 0) == 0) { */
    /*     wait4(pid, NULL, 0, NULL); */
    /*     long res = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * 1); */
    /*     printf("The child made a system call: %ld\n", res); */
    /* } */
    int status = 0;
    struct user_regs_struct u_in;
    struct ptrace_syscall_info info;
    struct
    {
        uint64_t nr;
        uint64_t args[6];
    } a;

    while (waitpid(pid, &status, 0) && !WIFEXITED(status)) {
        ptrace(PTRACE_GETREGS, pid, NULL, &u_in);
        printf("rax: %lld\n", u_in.orig_rax);
        /* ptrace(PTRACE_GET_SYSCALL_INFO, pid, sizeof info, &info); */
        /* printf("The child made a system call: %d\n", info.op); */
        /* for (size_t i = 0; i < info.entry.nr; i++) */
        /*     printf("arg[%ld]: %lld\n", i, info.entry.args[i]); */
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    }
    printf("The child tracing is now done.\n");
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
