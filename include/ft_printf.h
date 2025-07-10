/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:34:25 by squinn            #+#    #+#             */
/*   Updated: 2025/07/10 18:31:16 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1
# define MAX_ADDRESS_LENGTH 16

# define SINGLE_PERCENT_ERROR 1
# define LETTER 2
# define STRING 3
# define POINTER 4
# define INTEGER 5
# define UNSIGNED_INTEGER 6
# define LOWER_HEX 7
# define UPPER_HEX 8
# define PERCENT 9
# define UNKNOWN_CONVERSION_TYPE 10

int ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list args);
int print_by_conversion_type(int type, va_list args, char specifier);
int	determine_conversion_type(char letter);
int	ft_putchar(char c);
int	print_specifier(char specifier);
int	ft_putstr(const char *str);
int print_address(const void *addr);
char *unsigned_itoa(unsigned long long num, unsigned int base);


#endif
