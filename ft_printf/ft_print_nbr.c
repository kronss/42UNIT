/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:11:48 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/03 20:11:48 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_nbr(int n)
{
	unsigned int	nb;
	int len;

	len = 0;
	if (n < 0)
	{
		nb = -n;
		len += ft_print_char('-');
	}
	else
		nb = n;
	if (nb >= 10)
	{
		len += ft_print_nbr(nb / 10);
		len += ft_print_char((nb % 10) + '0');
	}
	else
		len += ft_print_char(nb + '0');
	return (len);
}

// int	main(int argc, char const *argv[])
// {
// 	int a = ft_print_nbr(-123);
// 	printf("\n%d\n", a);
// 	return 0;
// }