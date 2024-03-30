NAME := my_strace

ASM	:= nasm
ASMFLAGS := -f elf64

CC := gcc
CFLAGS := -std=c11
CFLAGS += -W -Wall -Wextra

LD := gcc
LDFLAGS	:= -fno-builtin

ASM_SRC	:= $(shell find ./src -name '*.S')
C_SRC	+= $(shell find ./src -name '*.c')

BUILD_DIR := .build
OBJ	:= $(ASM_SRC:%.S=$(BUILD_DIR)/%.o)
OBJ	+= $(C_SRC:%.c=$(BUILD_DIR)/%.o)

.PHONY: all
.DEFAULT_GOAL := all
all: $(NAME)

$(BUILD_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) -r $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
.NOTPARALLEL: re
re: fclean all
