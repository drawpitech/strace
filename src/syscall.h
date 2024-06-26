/*
** EPITECH PROJECT, 2021
** my_strace
** File description:
** syscall
*/

#pragma once

enum arg_type {
    NUM = 1,
    STRING = 2,
    UINT = 3,
    VOID_P = 4,
    CONST_VOID_P = 5,
    STRUCT_P = 7,
    STRUCT_STAT_P = 8,
    STRUCT_FD_P = 9,
    PVOID = 12,
    CONST_KERNEL_SIGSET_T_P = 13,
    KERNEL_SIGSET_T_P = 14,
    VARGS = 16,
    CONST_STRUCT_IOVEC_P = 17,
    FD_SET_P = 18,
    STRUCT_TIMEVAL_P = 19,
    VOID = 20,
    STRUCT_SHMID_DS_P = 23,
    CONST_STRUCT_TIMESPEC_P = 24,
    STRUCT_TIMESPEC_P = 25,
    STRUCT_ITIMERVAL_P = 26,
    CONST_STRUCT_ITIMERVAL_P = 28,
    CONST_STRUCT_SOCKADDR_P = 31,
    SOCKLEN_T = 32,
    STRUCT_SOCKADDR_P = 33,
    SOCKLEN_T_P = 34,
    CONST_STRUCT_MSGHDR_P = 35,
    STRUCT_MSGHDR_P = 36,
    STRUCT_RUSAGE_P = 39,
    STRUCT_UTSNAME_P = 40,
    STRUCT_SEMBUF_P = 41,
    STRUCT_MSQID_DS_P = 43,
    STRUCT_LINUX_DIRENT_P = 44,
    MODE_T = 49,
    UID_T = 51,
    GID_T = 52,
    STRUCT_TIMEZONE_P = 53,
    STRUCT_RLIMIT_P = 54,
    CLOCK_T = 55,
    STRUCT_TMS_P = 56,
    ENUM_____REQUEST = 57,
    CONST_GID_T_P = 58,
    UID_T_P = 59,
    GID_T_P = 60,
    CAP_USER_HEADER_T = 61,
    CAP_USER_DATA_T = 62,
    CONST_CAP_USER_DATA_T = 63,
    CONST_STACK_T_P = 64,
    STACK_T_P = 65,
    CONST_STRUCT_UTIMBUF_P = 66,
    DEV_T = 67,
    STRUCT_STATFS_P = 68,
    ID_T = 69,
    CONST_STRUCT_SCHED_PARAM_P = 70,
    STRUCT_SCHED_PARAM_P = 71,
    STRUCT_TIMESPEC_P_ = 72,
    STRUCT____ARGS_P = 73,
    STRUCT_TIMEX_P = 74,
    CONST_STRUCT_RLIMIT_P = 75,
    CONST_STRUCT_TIMEVAL_P = 76,
    CONST_STRUCT_TIMEZONE_P = 77,
    CADDR_T = 78,
    STRUCT_KERNEL_SYM_P = 79,
    NUM_P = 80,
    STRUCT_NFSCTL_ARG_P = 81,
    UNION_NFSCTL_RES_P = 82,
    OFF64_T = 83,
    TIME_T = 84,
    _T___T_P = 85,
    CONST_CPU_SET_T_P = 86,
    CPU_SET_T_P = 87,
    STRUCT_USER_DESC_P = 88,
    AIO_CONTEXT_T_P = 90,
    AIO_CONTEXT_T = 91,
    STRUCT_IO_EVENT_P = 92,
    STRUCT_IOCB_P = 93,
    U64 = 94,
    STRUCT_LINUX_DIRENT64_P = 95,
    CLOCKID_T = 96,
    STRUCT_SIGEVENT_P = 97,
    TIMER_T_P = 98,
    TIMER_T = 99,
    CONST_STRUCT_ITIMERSPEC_P = 100,
    STRUCT_ITIMERSPEC_P = 101,
    STRUCT_EPOLL_EVENT_P = 102,
    CONST_STRUCT_TIMEVAL = 103,
    CONST_UNSIGNED_P = 104,
    UNSIGNED_P = 105,
    MQD_T = 106,
    CONST_STRUCT_SIGEVENT_P = 108,
    STRUCT_MQ_ATTR_P = 109,
    STRUCT_KEXEC_SEGMENT_P = 110,
    IDTYPE_T = 111,
    SIGINFO_T_P = 112,
    KEY_SERIAL_T = 113,
    UNUM32_T = 114,
    STRUCT_POLLFD_P = 115,
    CONST_SIGSET_T_P = 116,
    STRUCT_ROBUST_LIST_HEAD_P = 117,
    LNUM_P = 118,
    CONST_NUM_P = 119,
    CONST_STRUCT_TIMESPEC = 120,
    STRUCT_PERF_EVENT_ATTR_P = 121,
    STRUCT_MMSGHDR_P = 122,
    UNUM64_T = 123,
    STRUCT_FILE_HANDLE_P = 124,
    STRUCT__CACHE_P = 126,
    STRUCT_SCHED_ATTR_P = 127,
    UNION__ATTR_P = 128,
};

typedef struct {
    char *name;
    enum arg_type ret_type;
    enum arg_type args[6];
} syscall_t;

static const syscall_t SYSCALLS[] = {
    {"read", NUM, {NUM, VOID_P, NUM, 0, 0, 0}},
    {"write", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"open", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"close", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"stat", NUM, {STRING, STRUCT_STAT_P, 0, 0, 0, 0}},
    {"fstat", NUM, {NUM, STRUCT_STAT_P, 0, 0, 0, 0}},
    {"lstat", NUM, {STRING, STRUCT_STAT_P, 0, 0, 0, 0}},
    {"poll", NUM, {STRUCT_FD_P, UINT, NUM, 0, 0, 0}},
    {"lseek", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"mmap", PVOID, {VOID_P, NUM, NUM, NUM, NUM, NUM}},
    {"mprotect", NUM, {VOID_P, NUM, NUM, 0, 0, 0}},
    {"munmap", NUM, {VOID_P, NUM, 0, 0, 0, 0}},
    {"brk", NUM, {VOID_P, 0, 0, 0, 0, 0}},
    {"rt_sigaction", 0, {0, 0, 0, 0, 0, 0}},
    {"rt_sigprocmask", NUM,
        {NUM, CONST_KERNEL_SIGSET_T_P, KERNEL_SIGSET_T_P, NUM, 0, 0}},
    {"rt_sigreturn", 0, {0, 0, 0, 0, 0, 0}},
    {"ioctl", NUM, {NUM, UINT, VARGS, 0, 0, 0}},
    {"pread64", 0, {0, 0, 0, 0, 0, 0}},
    {"pwrite64", 0, {0, 0, 0, 0, 0, 0}},
    {"readv", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, 0, 0, 0}},
    {"writev", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, 0, 0, 0}},
    {"access", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"pipe", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"select", NUM, {NUM, FD_SET_P, FD_SET_P, FD_SET_P, STRUCT_TIMEVAL_P, 0}},
    {"sched_yield", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"mremap", PVOID, {0, 0, 0, 0, 0, 0}},
    {"msync", NUM, {VOID_P, NUM, NUM, 0, 0, 0}},
    {"mincore", NUM, {VOID_P, NUM, STRING, 0, 0, 0}},
    {"madvise", NUM, {VOID_P, NUM, NUM, 0, 0, 0}},
    {"shmget", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"shmat", PVOID, {NUM, CONST_VOID_P, NUM, 0, 0, 0}},
    {"shmctl", NUM, {NUM, NUM, STRUCT_SHMID_DS_P, 0, 0, 0}},
    {"dup", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"dup2", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"pause", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"nanosleep", NUM,
        {CONST_STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, 0, 0, 0, 0}},
    {"getitimer", NUM, {NUM, STRUCT_ITIMERVAL_P, 0, 0, 0, 0}},
    {"alarm", UINT, {UINT, 0, 0, 0, 0, 0}},
    {"setitimer", NUM,
        {NUM, CONST_STRUCT_ITIMERVAL_P, STRUCT_ITIMERVAL_P, 0, 0, 0}},
    {"getpid", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"sendfile", NUM, {NUM, NUM, NUM_P, NUM, 0, 0}},
    {"socket", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"connect", NUM, {NUM, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T, 0, 0, 0}},
    {"accept", NUM, {NUM, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0}},
    {"sendto", NUM,
        {NUM, CONST_VOID_P, NUM, NUM, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T}},
    {"recvfrom", NUM, {NUM, VOID_P, NUM, NUM, STRUCT_SOCKADDR_P, SOCKLEN_T_P}},
    {"sendmsg", NUM, {NUM, CONST_STRUCT_MSGHDR_P, NUM, 0, 0, 0}},
    {"recvmsg", NUM, {NUM, STRUCT_MSGHDR_P, NUM, 0, 0, 0}},
    {"shutdown", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"bind", NUM, {NUM, CONST_STRUCT_SOCKADDR_P, SOCKLEN_T, 0, 0, 0}},
    {"listen", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"getsockname", NUM, {NUM, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0}},
    {"getpeername", NUM, {NUM, STRUCT_SOCKADDR_P, SOCKLEN_T_P, 0, 0, 0}},
    {"socketpair", NUM, {NUM, NUM, NUM, NUM, 0, 0}},
    {"setsockopt", NUM, {NUM, NUM, NUM, CONST_VOID_P, SOCKLEN_T, 0}},
    {"getsockopt", NUM, {NUM, NUM, NUM, VOID_P, SOCKLEN_T_P, 0}},
    {"clone", NUM, {0, 0, 0, 0, 0, 0}},
    {"fork", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"vfork", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"execve", NUM, {STRING, STRING, STRING, 0, 0, 0}},
    {"exit", 0, {0, 0, 0, 0, 0, 0}},
    {"wait4", NUM, {NUM, NUM_P, NUM, STRUCT_RUSAGE_P, 0, 0}},
    {"kill", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"uname", NUM, {STRUCT_UTSNAME_P, 0, 0, 0, 0, 0}},
    {"semget", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"semop", NUM, {NUM, STRUCT_SEMBUF_P, NUM, 0, 0, 0}},
    {"semctl", NUM, {NUM, NUM, NUM, VARGS, 0, 0}},
    {"shmdt", NUM, {CONST_VOID_P, 0, 0, 0, 0, 0}},
    {"msgget", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"msgsnd", NUM, {NUM, CONST_VOID_P, NUM, NUM, 0, 0}},
    {"msgrcv", NUM, {NUM, VOID_P, NUM, NUM, NUM, 0}},
    {"msgctl", NUM, {NUM, NUM, STRUCT_MSQID_DS_P, 0, 0, 0}},
    {"fcntl", NUM, {0, 0, 0, 0, 0, 0}},
    {"flock", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"fsync", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"fdatasync", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"truncate", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"ftruncate", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"getdents", NUM, {UINT, STRUCT_LINUX_DIRENT_P, UINT, 0, 0, 0}},
    {"getcwd", NUM, {STRING, UINT, 0, 0, 0, 0}},
    {"chdir", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"fchdir", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"rename", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"mkdir", NUM, {STRING, MODE_T, 0, 0, 0, 0}},
    {"rmdir", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"creat", NUM, {STRING, MODE_T, 0, 0, 0, 0}},
    {"link", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"unlink", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"symlink", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"readlink", NUM, {STRING, STRING, NUM, 0, 0, 0}},
    {"chmod", NUM, {STRING, MODE_T, 0, 0, 0, 0}},
    {"fchmod", NUM, {NUM, MODE_T, 0, 0, 0, 0}},
    {"chown", NUM, {STRING, UID_T, GID_T, 0, 0, 0}},
    {"fchown", NUM, {NUM, UID_T, GID_T, 0, 0, 0}},
    {"lchown", NUM, {STRING, UID_T, GID_T, 0, 0, 0}},
    {"umask", MODE_T, {MODE_T, 0, 0, 0, 0, 0}},
    {"gettimeofday", NUM, {STRUCT_TIMEVAL_P, STRUCT_TIMEZONE_P, 0, 0, 0, 0}},
    {"getrlimit", NUM, {NUM, STRUCT_RLIMIT_P, 0, 0, 0, 0}},
    {"getrusage", NUM, {NUM, STRUCT_RUSAGE_P, 0, 0, 0, 0}},
    {"sysinfo", NUM, {STRUCT_P, 0, 0, 0, 0, 0}},
    {"times", CLOCK_T, {STRUCT_TMS_P, 0, 0, 0, 0, 0}},
    {"ptrace", NUM, {ENUM_____REQUEST, NUM, VOID_P, VOID_P, 0, 0}},
    {"getuid", UID_T, {VOID, 0, 0, 0, 0, 0}},
    {"syslog", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"getgid", GID_T, {VOID, 0, 0, 0, 0, 0}},
    {"setuid", NUM, {UID_T, 0, 0, 0, 0, 0}},
    {"setgid", NUM, {GID_T, 0, 0, 0, 0, 0}},
    {"geteuid", UID_T, {VOID, 0, 0, 0, 0, 0}},
    {"getegid", GID_T, {VOID, 0, 0, 0, 0, 0}},
    {"setpgid", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"getppid", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"getpgrp", NUM, {0, 0, 0, 0, 0, 0}},
    {"setsid", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"setreuid", NUM, {UID_T, UID_T, 0, 0, 0, 0}},
    {"setregid", NUM, {GID_T, GID_T, 0, 0, 0, 0}},
    {"getgroups", NUM, {NUM, GID_T, 0, 0, 0, 0}},
    {"setgroups", NUM, {NUM, CONST_GID_T_P, 0, 0, 0, 0}},
    {"setresuid", NUM, {UID_T, UID_T, UID_T, 0, 0, 0}},
    {"getresuid", NUM, {UID_T_P, UID_T_P, UID_T_P, 0, 0, 0}},
    {"setresgid", NUM, {GID_T, GID_T, GID_T, 0, 0, 0}},
    {"getresgid", NUM, {GID_T_P, GID_T_P, GID_T_P, 0, 0, 0}},
    {"getpgid", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"setfsuid", NUM, {UID_T, 0, 0, 0, 0, 0}},
    {"setfsgid", NUM, {UID_T, 0, 0, 0, 0, 0}},
    {"getsid", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"capget", NUM, {CAP_USER_HEADER_T, CAP_USER_DATA_T, 0, 0, 0, 0}},
    {"capset", NUM, {CAP_USER_HEADER_T, CONST_CAP_USER_DATA_T, 0, 0, 0, 0}},
    {"rt_sigpending", 0, {0, 0, 0, 0, 0, 0}},
    {"rt_sigtimedwait", 0, {0, 0, 0, 0, 0, 0}},
    {"rt_sigqueueinfo", 0, {0, 0, 0, 0, 0, 0}},
    {"rt_sigsuspend", 0, {0, 0, 0, 0, 0, 0}},
    {"sigaltstack", NUM, {CONST_STACK_T_P, STACK_T_P, 0, 0, 0, 0}},
    {"utime", NUM, {STRING, CONST_STRUCT_UTIMBUF_P, 0, 0, 0, 0}},
    {"mknod", NUM, {STRING, MODE_T, DEV_T, 0, 0, 0}},
    {"uselib", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"personality", NUM, {UINT, 0, 0, 0, 0, 0}},
    {"ustat", NUM, {DEV_T, STRUCT_P, 0, 0, 0, 0}},
    {"statfs", NUM, {STRING, STRUCT_P, 0, 0, 0, 0}},
    {"fstatfs", NUM, {NUM, STRUCT_STATFS_P, 0, 0, 0, 0}},
    {"sysfs", NUM, {NUM, STRING, 0, 0, 0, 0}},
    {"getpriority", NUM, {NUM, ID_T, 0, 0, 0, 0}},
    {"setpriority", NUM, {NUM, ID_T, NUM, 0, 0, 0}},
    {"sched_setparam", NUM, {NUM, CONST_STRUCT_SCHED_PARAM_P, 0, 0, 0, 0}},
    {"sched_getparam", NUM, {NUM, STRUCT_SCHED_PARAM_P, 0, 0, 0, 0}},
    {"sched_setscheduler", NUM,
        {NUM, NUM, CONST_STRUCT_SCHED_PARAM_P, 0, 0, 0}},
    {"sched_getscheduler", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"sched_get_priority_max", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"sched_get_priority_min", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"sched_rr_get_interval", NUM, {NUM, STRUCT_TIMESPEC_P_, 0, 0, 0, 0}},
    {"mlock", NUM, {CONST_VOID_P, NUM, 0, 0, 0, 0}},
    {"munlock", NUM, {CONST_VOID_P, NUM, 0, 0, 0, 0}},
    {"mlockall", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"munlockall", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"vhangup", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"modify_ldt", NUM, {NUM, VOID_P, UINT, 0, 0, 0}},
    {"pivot_root", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"_sysctl", NUM, {STRUCT____ARGS_P, 0, 0, 0, 0, 0}},
    {"prctl", NUM, {NUM, UINT, UINT, UINT, UINT, 0}},
    {"arch_prctl", NUM, {NUM, UINT, 0, 0, 0, 0}},
    {"adjtimex", NUM, {STRUCT_TIMEX_P, 0, 0, 0, 0, 0}},
    {"setrlimit", NUM, {NUM, CONST_STRUCT_RLIMIT_P, 0, 0, 0, 0}},
    {"chroot", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"sync", VOID, {VOID, 0, 0, 0, 0, 0}},
    {"acct", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"settimeofday", NUM,
        {CONST_STRUCT_TIMEVAL_P, CONST_STRUCT_TIMEZONE_P, 0, 0, 0, 0}},
    {"mount", NUM, {STRING, STRING, STRING, UINT, CONST_VOID_P, 0}},
    {"umount2", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"swapon", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"swapoff", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"reboot", NUM, {NUM, NUM, NUM, VOID_P, 0, 0}},
    {"sethostname", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"setdomainname", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"iopl", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"ioperm", NUM, {UINT, UINT, NUM, 0, 0, 0}},
    {"create_module", CADDR_T, {STRING, NUM, 0, 0, 0, 0}},
    {"init_module", NUM, {VOID_P, UINT, STRING, 0, 0, 0}},
    {"delete_module", NUM, {STRING, NUM, 0, 0, 0, 0}},
    {"get_kernel_syms", NUM, {STRUCT_KERNEL_SYM_P, 0, 0, 0, 0, 0}},
    {"query_module", NUM, {STRING, NUM, VOID_P, NUM, NUM_P, 0}},
    {"quotactl", NUM, {NUM, STRING, NUM, CADDR_T, 0, 0}},
    {"nfsservctl", NUM,
        {NUM, STRUCT_NFSCTL_ARG_P, UNION_NFSCTL_RES_P, 0, 0, 0}},
    {"getpmsg", 0, {0, 0, 0, 0, 0, 0}},
    {"putpmsg", 0, {0, 0, 0, 0, 0, 0}},
    {"afs_syscall", 0, {0, 0, 0, 0, 0, 0}},
    {"tuxcall", 0, {0, 0, 0, 0, 0, 0}},
    {"security", 0, {0, 0, 0, 0, 0, 0}},
    {"gettid", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"readahead", NUM, {NUM, OFF64_T, NUM, 0, 0, 0}},
    {"setxattr", NUM, {STRING, STRING, CONST_VOID_P, NUM, NUM, 0}},
    {"lsetxattr", NUM, {STRING, STRING, CONST_VOID_P, NUM, NUM, 0}},
    {"fsetxattr", NUM, {NUM, STRING, CONST_VOID_P, NUM, NUM, 0}},
    {"getxattr", NUM, {STRING, STRING, VOID_P, NUM, 0, 0}},
    {"lgetxattr", NUM, {STRING, STRING, VOID_P, NUM, 0, 0}},
    {"fgetxattr", NUM, {NUM, STRING, VOID_P, NUM, 0, 0}},
    {"listxattr", NUM, {STRING, STRING, NUM, 0, 0, 0}},
    {"llistxattr", NUM, {STRING, STRING, NUM, 0, 0, 0}},
    {"flistxattr", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"removexattr", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"lremovexattr", NUM, {STRING, STRING, 0, 0, 0, 0}},
    {"fremovexattr", NUM, {NUM, STRING, 0, 0, 0, 0}},
    {"tkill", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"time", TIME_T, {_T___T_P, 0, 0, 0, 0, 0}},
    {"futex", NUM, {0, 0, 0, 0, 0, 0}},
    {"sched_setaffinity", NUM, {NUM, NUM, CONST_CPU_SET_T_P, 0, 0, 0}},
    {"sched_getaffinity", NUM, {NUM, NUM, CPU_SET_T_P, 0, 0, 0}},
    {"set_thread_area", NUM, {STRUCT_USER_DESC_P, 0, 0, 0, 0, 0}},
    {"io_setup", NUM, {UINT, AIO_CONTEXT_T_P, 0, 0, 0, 0}},
    {"io_destroy", NUM, {AIO_CONTEXT_T, 0, 0, 0, 0, 0}},
    {"io_getevents", NUM,
        {AIO_CONTEXT_T, NUM, NUM, STRUCT_IO_EVENT_P, STRUCT_TIMESPEC_P, 0}},
    {"io_submit", NUM, {AIO_CONTEXT_T, NUM, STRUCT_IOCB_P, 0, 0, 0}},
    {"io_cancel", NUM,
        {AIO_CONTEXT_T, STRUCT_IOCB_P, STRUCT_IO_EVENT_P, 0, 0, 0}},
    {"get_thread_area", NUM, {STRUCT_USER_DESC_P, 0, 0, 0, 0, 0}},
    {"lookup_dcookie", NUM, {U64, STRING, NUM, 0, 0, 0}},
    {"epoll_create", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"epoll_ctl_old", 0, {0, 0, 0, 0, 0, 0}},
    {"epoll_wait_old", 0, {0, 0, 0, 0, 0, 0}},
    {"remap_file_pages", NUM, {VOID_P, NUM, NUM, NUM, NUM, 0}},
    {"getdents64", NUM,
        {UINT, STRUCT_LINUX_DIRENT64_P, UINT, 0, 0, 0}},
    {"set_tid_address", NUM, {NUM_P, 0, 0, 0, 0, 0}},
    {"restart_syscall", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"semtimedop", NUM,
        {NUM, STRUCT_SEMBUF_P, NUM, CONST_STRUCT_TIMESPEC_P, 0, 0}},
    {"fadvise64", 0, {0, 0, 0, 0, 0, 0}},
    {"timer_create", NUM, {CLOCKID_T, STRUCT_SIGEVENT_P, TIMER_T_P, 0, 0, 0}},
    {"timer_settime", NUM,
        {TIMER_T, NUM, CONST_STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P, 0, 0}},
    {"timer_gettime", NUM, {TIMER_T, STRUCT_ITIMERSPEC_P, 0, 0, 0, 0}},
    {"timer_getoverrun", NUM, {TIMER_T, 0, 0, 0, 0, 0}},
    {"timer_delete", NUM, {TIMER_T, 0, 0, 0, 0, 0}},
    {"clock_settime", NUM, {CLOCKID_T, CONST_STRUCT_TIMESPEC_P, 0, 0, 0, 0}},
    {"clock_gettime", NUM, {CLOCKID_T, STRUCT_TIMESPEC_P, 0, 0, 0, 0}},
    {"clock_getres", NUM, {CLOCKID_T, STRUCT_TIMESPEC_P, 0, 0, 0, 0}},
    {"clock_nanosleep", NUM,
        {CLOCKID_T, NUM, CONST_STRUCT_TIMESPEC_P, STRUCT_TIMESPEC_P, 0, 0}},
    {"exit_group", VOID, {NUM, 0, 0, 0, 0, 0}},
    {"epoll_wait", NUM, {NUM, STRUCT_EPOLL_EVENT_P, NUM, NUM, 0, 0}},
    {"epoll_ctl", NUM, {NUM, NUM, NUM, STRUCT_EPOLL_EVENT_P, 0, 0}},
    {"tgkill", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"utimes", NUM, {STRING, CONST_STRUCT_TIMEVAL, 0, 0, 0, 0}},
    {"vserver", 0, {0, 0, 0, 0, 0, 0}},
    {"mbind", NUM,
        {VOID_P, UINT, NUM, CONST_UNSIGNED_P, UINT, UINT}},
    {"set_mempolicy", NUM, {NUM, CONST_UNSIGNED_P, UINT, 0, 0, 0}},
    {"get_mempolicy", NUM, {NUM_P, UNSIGNED_P, UINT, VOID_P, UINT, 0}},
    {"mq_open", MQD_T, {STRING, NUM, 0, 0, 0, 0}},
    {"mq_unlink", NUM, {STRING, 0, 0, 0, 0, 0}},
    {"mq_timedsend", NUM,
        {MQD_T, STRING, NUM, UINT, CONST_STRUCT_TIMESPEC_P, 0}},
    {"mq_timedreceive", NUM,
        {MQD_T, STRING, NUM, UNSIGNED_P, CONST_STRUCT_TIMESPEC_P, 0}},
    {"mq_notify", NUM, {MQD_T, CONST_STRUCT_SIGEVENT_P, 0, 0, 0, 0}},
    {"mq_getsetattr", NUM,
        {MQD_T, STRUCT_MQ_ATTR_P, STRUCT_MQ_ATTR_P, 0, 0, 0}},
    {"kexec_load", NUM,
        {UINT, UINT, STRUCT_KEXEC_SEGMENT_P, UINT, 0, 0}},
    {"waitid", NUM, {IDTYPE_T, ID_T, SIGINFO_T_P, NUM, 0, 0}},
    {"add_key", KEY_SERIAL_T,
        {STRING, STRING, CONST_VOID_P, NUM, KEY_SERIAL_T, 0}},
    {"request_key", KEY_SERIAL_T,
        {STRING, STRING, STRING, KEY_SERIAL_T, 0, 0}},
    {"keyctl", NUM, {NUM, VARGS, 0, 0, 0, 0}},
    {"ioprio_set", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"ioprio_get", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"inotify_init", NUM, {VOID, 0, 0, 0, 0, 0}},
    {"inotify_add_watch", NUM, {NUM, STRING, UNUM32_T, 0, 0, 0}},
    {"inotify_rm_watch", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"migrate_pages", NUM,
        {NUM, UINT, CONST_UNSIGNED_P, CONST_UNSIGNED_P, 0, 0}},
    {"openat", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"mkdirat", NUM, {NUM, STRING, MODE_T, 0, 0, 0}},
    {"mknodat", NUM, {NUM, STRING, MODE_T, DEV_T, 0, 0}},
    {"fchownat", NUM, {NUM, STRING, UID_T, GID_T, NUM, 0}},
    {"futimesat", NUM, {NUM, STRING, CONST_STRUCT_TIMEVAL, 0, 0, 0}},
    {"newfstatat", 0, {0, 0, 0, 0, 0, 0}},
    {"unlinkat", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"renameat", NUM, {NUM, STRING, NUM, STRING, 0, 0}},
    {"linkat", NUM, {NUM, STRING, NUM, STRING, NUM, 0}},
    {"symlinkat", NUM, {STRING, NUM, STRING, 0, 0, 0}},
    {"readlinkat", NUM, {NUM, STRING, STRING, NUM, 0, 0}},
    {"fchmodat", NUM, {NUM, STRING, MODE_T, NUM, 0, 0}},
    {"faccessat", NUM, {NUM, STRING, NUM, NUM, 0, 0}},
    {"pselect6", 0, {0, 0, 0, 0, 0, 0}},
    {"ppoll",
        NUM, {
            STRUCT_POLLFD_P,
            UINT,
            CONST_STRUCT_TIMESPEC_P,
            CONST_SIGSET_T_P,
            0,
            0
        }
    },
    {"unshare", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"set_robust_list", NUM, {STRUCT_ROBUST_LIST_HEAD_P, NUM, 0, 0, 0, 0}},
    {"get_robust_list", NUM, {NUM, STRUCT_ROBUST_LIST_HEAD_P, NUM_P, 0, 0, 0}},
    {"splice", NUM, {NUM, LNUM_P, NUM, LNUM_P, NUM, UINT}},
    {"tee", NUM, {NUM, NUM, NUM, UINT, 0, 0}},
    {"sync_file_range", NUM, {NUM, OFF64_T, OFF64_T, UINT, 0, 0}},
    {"vmsplice", NUM, {NUM, CONST_STRUCT_IOVEC_P, UINT, UINT, 0, 0}},
    {"move_pages", NUM, {NUM, UINT, VOID_P, CONST_NUM_P, NUM_P, NUM}},
    {"utimensat", NUM, {NUM, STRING, CONST_STRUCT_TIMESPEC, NUM, 0, 0}},
    {"epoll_pwait", NUM,
        {NUM, STRUCT_EPOLL_EVENT_P, NUM, NUM, CONST_SIGSET_T_P, 0}},
    {"signalfd", NUM, {NUM, CONST_SIGSET_T_P, NUM, 0, 0, 0}},
    {"timerfd_create", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"eventfd", NUM, {UINT, NUM, 0, 0, 0, 0}},
    {"fallocate", NUM, {NUM, NUM, NUM, NUM, 0, 0}},
    {"timerfd_settime", NUM,
        {NUM, NUM, CONST_STRUCT_ITIMERSPEC_P, STRUCT_ITIMERSPEC_P, 0, 0}},
    {"timerfd_gettime", NUM, {NUM, STRUCT_ITIMERSPEC_P, 0, 0, 0, 0}},
    {"accept4", NUM, {NUM, STRUCT_SOCKADDR_P, SOCKLEN_T_P, NUM, 0, 0}},
    {"signalfd4", 0, {0, 0, 0, 0, 0, 0}},
    {"eventfd2", 0, {0, 0, 0, 0, 0, 0}},
    {"epoll_create1", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"dup3", NUM, {NUM, NUM, NUM, 0, 0, 0}},
    {"pipe2", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"inotify_init1", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"preadv", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, NUM, 0, 0}},
    {"pwritev", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, NUM, 0, 0}},
    {"rt_tgsigqueueinfo", 0, {0, 0, 0, 0, 0, 0}},
    {"perf_event_open", NUM,
        {STRUCT_PERF_EVENT_ATTR_P, NUM, NUM, NUM, UINT, 0}},
    {"recvmmsg", NUM,
        {NUM, STRUCT_MMSGHDR_P, UINT, UINT, STRUCT_TIMESPEC_P, 0}},
    {"fanotify_init", NUM, {UINT, UINT, 0, 0, 0, 0}},
    {"fanotify_mark", NUM, {NUM, UINT, UNUM64_T, NUM, STRING, 0}},
    {"prlimit64", 0, {0, 0, 0, 0, 0, 0}},
    {"name_to_handle_at", NUM,
        {NUM, STRING, STRUCT_FILE_HANDLE_P, NUM_P, NUM, 0}},
    {"open_by_handle_at", NUM, {NUM, STRUCT_FILE_HANDLE_P, NUM, 0, 0, 0}},
    {"clock_adjtime", 0, {0, 0, 0, 0, 0, 0}},
    {"syncfs", NUM, {NUM, 0, 0, 0, 0, 0}},
    {"sendmmsg", NUM, {NUM, STRUCT_MMSGHDR_P, UINT, UINT, 0, 0}},
    {"setns", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"getcpu", NUM, {UNSIGNED_P, UNSIGNED_P, STRUCT__CACHE_P, 0, 0, 0}},
    {"process_vm_readv",
        NUM, {
            NUM,
            CONST_STRUCT_IOVEC_P,
            UINT,
            CONST_STRUCT_IOVEC_P,
            UINT,
            UINT
    }},
    {"process_vm_writev",
        NUM, {
            NUM,
            CONST_STRUCT_IOVEC_P,
            UINT,
            CONST_STRUCT_IOVEC_P,
            UINT,
            UINT
    }},
    {"kcmp", NUM, {NUM, NUM, NUM, UINT, UINT, 0}},
    {"finit_module", NUM, {NUM, STRING, NUM, 0, 0, 0}},
    {"sched_setattr", NUM, {NUM, STRUCT_SCHED_ATTR_P, UINT, 0, 0, 0}},
    {"sched_getattr", NUM,
        {NUM, STRUCT_SCHED_ATTR_P, UINT, UINT, 0, 0}},
    {"renameat2", NUM, {NUM, STRING, NUM, STRING, UINT, 0}},
    {"seccomp", NUM, {UINT, UINT, VOID_P, 0, 0, 0}},
    {"getrandom", NUM, {VOID_P, NUM, UINT, 0, 0, 0}},
    {"memfd_create", NUM, {STRING, UINT, 0, 0, 0, 0}},
    {"kexec_file_load", NUM, {NUM, NUM, UINT, STRING, UINT, 0}},
    {"bpf", NUM, {NUM, UNION__ATTR_P, UINT, 0, 0, 0}},
    {"execveat", NUM, {NUM, STRING, STRING, STRING, NUM, 0}},
    {"userfaultfd", 0, {0, 0, 0, 0, 0, 0}},
    {"membarrier", NUM, {NUM, NUM, 0, 0, 0, 0}},
    {"mlock2", NUM, {CONST_VOID_P, NUM, NUM, 0, 0, 0}},
    {"copy_file_range", NUM, {NUM, LNUM_P, NUM, LNUM_P, NUM, UINT}},
    {"preadv2", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, NUM, NUM, 0}},
    {"pwritev2", NUM, {NUM, CONST_STRUCT_IOVEC_P, NUM, NUM, NUM, 0}},
};
