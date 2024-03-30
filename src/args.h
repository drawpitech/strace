/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** args
*/

#pragma once

#include <stdbool.h>
#include <sys/types.h>

#include "strace.h"

enum flags_e {
    HELP = 1 << 0,
    FULL = 1 << 1,
    PID = 1 << 2,
};

typedef struct {
    char c;
    const char *name;
    enum flags_e flag;
    const char *desc;
} flag_t;

static const flag_t OPTIONS[] = {
    {'h', "help", HELP, "Display this help message"},
    {'s', "full", FULL, "As close as possible to the strace command"},
    {'p', "pid", PID, "Force a specific PID instead of executing a command"},
};

void get_args(int argc, char **argv, strace_t *strace);
