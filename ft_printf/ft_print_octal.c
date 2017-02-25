/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 23:22:36 by ochayche          #+#    #+#             */
/*   Updated: 2017/01/26 23:22:37 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// int 		ft_len(int nbr)
// {
// 	while (nbr > 0)
// 	{
// 		nbr /= 10;
// 	}
// 	printf("%d\n", len);
// 	return (len);
// }

int			ft_print_octal(unsigned nbr)
{
	char	*base;
	int		len;
	
	if (nbr == 0)
		return (0);
	len = 1;
	base = "01234567";

	len += ft_print_octal(nbr/8);
	write(1, &base[nbr % 8], 1);
	return (len);
}

// int	main(void)
// {
// 	int nbr;

// 	nbr = -128;
// 	int len = ft_print_octal(nbr);

// 	write(1, "\n", 1);
// 	printf("len %d\n", len);
// 	return 0;
// }