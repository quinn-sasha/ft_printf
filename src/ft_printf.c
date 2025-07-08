/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:11:21 by squinn            #+#    #+#             */
/*   Updated: 2025/07/08 16:32:26 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	determine_conversion_type(char letter)
{
	if (letter == '\0')
		return (SINGLE_PERCENT_ERROR);
	if (letter == 'c')
		return (LETTER);
	if (letter == 's')
		return (STRING);
	if (letter == 'p')
		return (POINTER);
	if (letter == 'd' || letter == 'i')
		return (INTEGER);
	if (letter == 'u')
		return (UNSIGNED_INTEGER);
	if (letter == 'x')
		return (LOWER_HEX);
	if (letter == 'X')
		return (UPPER_HEX);
	if (letter == '%')
		return (PERCENT);
	return (UNKNOWN_CONVERSION_TYPE);
}

print_by_conversion_type(int type, va_list args)
{
	int	num_bytes;

	num_bytes = 0;
	
	return (num_bytes);
}

int	ft_vprintf(const char *format, va_list args)
{
	int	result;
	int	conversion;

	result = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, STDOUT);
			result++;
			format++;
			continue;
		}
		format++;
		conversion = determine_conversion_type(*format);
		if (conversion == SINGLE_PERCENT_ERROR)
			return (-1);
		result += print_by_conversion_type();
		format++;
	}
	return result;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int result;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}
