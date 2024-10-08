/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:16:07 by hakaddou          #+#    #+#             */
/*   Updated: 2024/09/13 18:45:31 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		length;

	length = 0;
	i = 0;
	va_start (ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			length += ft_putchar (str[i]);
			i++;
		}
		else
		{
			length += ft_parse (ptr, str[i + 1]);
			i += 2;
		}
	}
	va_end (ptr);
	return (length);
}

int main() {

	char str[] = "hello world";

	ft_printf("str is %s\n", str);
}