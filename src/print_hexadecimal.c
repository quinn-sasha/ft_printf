/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:46:20 by squinn            #+#    #+#             */
/*   Updated: 2025/07/11 13:50:56 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_hexadecimal(unsigned int n, int is_upper)
{
	unsigned long long	num;
	char				*buffer;
	int					i;

	num = (unsigned long long)n;
	buffer = unsigned_itoa(num, 16);
	if (is_upper)
	{
		i = 0;
		while (buffer[i])
		{
			buffer[i] = (char)ft_toupper(buffer[i]);
			i++;
		}
	}
	return (ft_putstr(buffer));
}
