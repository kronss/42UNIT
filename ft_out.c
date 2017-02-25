/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:39:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/16 20:39:20 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	choose conversions: % s S p d D i o O u U x X c C
*/

#include "ft_printf.h"

int		ft_out(t_list *lst, va_list va)
{
	if (lst->spec == '%')
		return (ft_print_percent(lst, '%'));
	else if (lst->spec == 'c' || lst->spec ==  'C')
		return (ft_hendling_char(lst, va_arg(va, void *)));
	else if (lst->spec == 's' || lst->spec ==  'S')
		return (ft_hendling_str(lst, va_arg(va, void *)));
	else if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'D')
		return (ft_hendling_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'u' || lst->spec == 'U')
		return (ft_hendling_unsigned_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'x' || lst->spec == 'X')
		return (ft_hendling_x(lst, va_arg(va, void *)));
	else if (lst->spec == 'o' || lst->spec == 'O')
		return (ft_hendling_o(lst, va_arg(va, void *)));
	else if (lst->spec == 'p')
		return (ft_hendling_ptr(lst, va_arg(va, void *)));
	else 
		return (ft_hendling_char(lst, va_arg(va, void *)));
}

// if (!(ft_strchr_f("%sSpdDioOuUxXcC", lst->spec)) && lst->spec != '\0')