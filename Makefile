# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 14:49:54 by squinn            #+#    #+#              #
#    Updated: 2025/07/11 15:49:03 by squinn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
AR := ar
CC := cc
CFLAGS := -Wall -Wextra -Werror -I
RM := rm -f
RMDIR := rm -rf

SRCDIR := src
OBJDIR := obj
INCLUDE := include
LIBFTDIR := libft
TEMPDIR := temp_dir

SRCFILES := ft_printf.c \
            print_address.c \
			printf_utils.c \
			print_hexadecimal.c \
			unsigned_itoa.c


SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT := $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	mkdir -p $(TEMPDIR)
	cp $(LIBFT) $(TEMPDIR)
	cd $(TEMPDIR) && $(AR) x ../$(LIBFT)
	$(AR) rcs $@ $(OBJS) $(TEMPDIR)/*.o
	$(RMDIR) $(TEMPDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RMDIR) $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

test: $(NAME)
	gcc -Wno-format test.c $(NAME) -D TEST_FT_PRINTF -o test_ft_printf
	gcc -Wno-format test.c -o test_printf
	./test_ft_printf > ft_printf_output.txt
	./test_printf > printf_output.txt
	diff --suppress-common-lines --text ft_printf_output.txt printf_output.txt
	$(RM) test_ft_printf test_printf ft_printf_output.txt printf_output.txt
