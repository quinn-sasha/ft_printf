/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:35:08 by squinn            #+#    #+#             */
/*   Updated: 2025/07/10 14:18:10 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	int	num_bytes;

	num_bytes = write(STDOUT, &c, 1);
	if (num_bytes == -1)
		return (0);
	return (num_bytes);
}

int	print_specifier(char specifier)
{
	int	num_bytes;

	num_bytes = 0;
	num_bytes += ft_putchar('%');
	num_bytes += ft_putchar(specifier);
	if (num_bytes < 0)
		return (0);
	return (num_bytes);
}

int	ft_putstr(const char *str)
{
	int	num_bytes;

	if (str == NULL)
		return ft_putstr("(null)");
	num_bytes = 0;
	while (*str)
	{
		num_bytes += ft_putchar(*str);
		str++;
	}
	return (num_bytes);
}
