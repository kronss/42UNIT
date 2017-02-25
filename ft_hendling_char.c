/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hendling_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:46:22 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/18 12:46:23 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	handling the %char;
*/

#include "ft_printf.h"

int					ft_hendling_char(t_list *lst, void *c)
{
	int				len;

	len = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[3] != '-' && lst->width > 1)
		while (((lst->width)-- - 1))
			len += ft_print_char((lst->flags)[0]);
	if (lst->spec == 'c' && !lst->l)
		len += ft_print_char((int)c);
	if (lst->spec == 'C' || (lst->spec == 'c' && lst->l))
		len += ft_print_char((int)c);
	if (lst->width > 1 && (lst->flags)[3] == '-')
		while ((lst->width)-- - 1)
			len += ft_print_char(' ');
	return (len);
}
