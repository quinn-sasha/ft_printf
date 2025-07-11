/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:11:21 by squinn            #+#    #+#             */
/*   Updated: 2025/07/11 11:52:19 by squinn           ###   ########.fr       */
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

int print_by_conversion_type(int type, va_list args, char specifier)
{
	// TODO: 条件分岐してプリント、プリントしたバイト数を加算する
	if (type == UNKNOWN_CONVERSION_TYPE)
		return print_specifier(specifier);
	if (type == LETTER)
	{
		char letter = va_arg(args, char);
		return ft_putchar(letter);
	}
	if (type == STRING)
	{
		char *str = va_arg(args, char *);
		return ft_putstr(str);
	}
	if (type == POINTER)
	{
		void *address = va_arg(args, void *);
		return print_address(address);
	}
	if (type == INTEGER)
	{
		int	num = va_arg(args, int);
		return ft_putnbr(num);
	}
	if (type == UNSIGNED_INTEGER)
	{}
	if (type == LOWER_HEX)
	{}
	if (type == UPPER_HEX)
	{}
	if (type == PERCENT)
}

int	ft_vprintf(const char *format, va_list args)
{
	int	result;
	int	type;

	result = 0;
	while (*format)
	{
		if (*format != '%')
		{
			result += ft_putchar(*format);
			format++;
			continue;
		}
		format++;
		type = determine_conversion_type(*format);
		if (type == SINGLE_PERCENT_ERROR)
			return (-1);
		result += print_by_conversion_type(type, args, *format);
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
