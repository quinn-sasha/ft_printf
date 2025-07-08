/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:34:25 by squinn            #+#    #+#             */
/*   Updated: 2025/07/08 15:12:02 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "../libft/libft.h"
# include <stdarg.h>

# define STDOUT 1

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

#endif
