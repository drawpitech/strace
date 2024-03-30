/*
** EPITECH PROJECT, 2024
** my_strace
** File description:
** args
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "args.h"
#include "strace.h"

static void print_help(void)
{
    printf("Usage: strace [options] [-p <pid>|<command>]\n");
    printf("Options:\n");
    for (size_t i = 0; LENGTH(OPTIONS); i++) {
        printf("\t");
        if (OPTIONS[i].flag)
            printf("-%c ", OPTIONS[i].c);
        if (OPTIONS[i].name != NULL)
            printf("--%s", OPTIONS[i].name);
        printf(":\t%s\n", OPTIONS[i].desc);
    }
}

void get_args(int argc, char **argv, args_t *flags)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            exit(RET_VALID);
        }
        if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--full") == 0) {
            flags->flag |= FULL;
            continue;
        }
        if (strcmp(argv[i], "-p") == 0 && argv[i + 1] != NULL) {
            flags->flag |= PID;
            flags->pid = atoi(argv[i]);
            i += 1;
        }
        if (argv[i][0] == '-' || flags->filename != NULL) {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            exit(RET_ERROR);
        }
        flags->filename = argv[i];
    }
}
