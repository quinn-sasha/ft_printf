# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 17:28:47 by squinn            #+#    #+#              #
#    Updated: 2025/07/08 11:09:58 by squinn           ###   ########.fr        #
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

SRCFILES := # TODO

SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT := $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	mkdir -p $(TEMPDIR)
	cd $(TEMPDIR) && $(AR) x ../$(LIBFT)
	$(AR) rcs $(NAME) $(OBJS) $(TEMPDIR)/%.o
	$(RMDIR) $(TEMPDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)%.c
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
	gcc test.c $(NAME) -D TEST_FT_PRINTF -o test_ft_printf
	gcc test.c -o test_printf
	./test_ft_printf > ft_printf_output.txt
	./test_printf > printf_output.txt
	diff --suppress-common-lines --text ft_printf_output.txt printf_output.txt
	$(RM) test_ft_printf test_printf ft_printf_output.txt printf_output.txt
