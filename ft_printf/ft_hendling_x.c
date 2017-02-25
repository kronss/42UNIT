/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hendling_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:06:54 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/24 19:06:55 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char				ft_strlen_x_digit(t_list *lst, intmax_t digit)
{
	char	res;
	char	tmp;
	intmax_t digit_tmp;
	
	tmp = 0;
	digit_tmp = digit;
	res = 1;

	digit_tmp /= 16;
	while (digit_tmp)
	{
		digit_tmp /= 16;
		res++;
	}
	if (lst->precision != -1 && lst->precision > res)
	{
		tmp = (lst->precision - res);
		res = lst->precision;
	}
	if (lst->flags[1] == '#' && digit != 0)
		res += 2;
	if (tmp > 0)
		lst->precision = tmp;
	else if (digit == 0 && lst->precision == 0)
	{
		lst->precision = -2;
		res = 0;
	}
	else
		lst->precision = -1;
	return (res);
}


static char			ft_print_x_digit(uintmax_t digit, t_list *lst, char *base)
{
	char len;

	len = 0;
	// printf("size precision (%d)\n", lst->precision);
	// printf("size size (%d)\n", lst->size);
	// printf("size width (%d)\n", lst->width);

	if (digit == 0 && lst->precision == -2)
		return (0);

	if (digit >= 16)
	{
		len += ft_print_x_digit(digit / 16, lst, base);
		len += ft_print_char(base[digit % 16]);
	}
	else
		len += ft_print_char(base[digit % 16]);
	return (len);
}





static short ft_hend_x_digit(t_list *lst, uintmax_t digit)
{
	short len;

	len = 0;
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';

	lst->size = ft_strlen_x_digit(lst, digit);
	
	if (lst->flags[0] == '0' && lst->flags[1] == '#' && digit != 0)
		len += (lst->spec == 'X') ? (ft_print_str("0X", -1)) : (ft_print_str("0x", -1));

	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(len += ft_print_char((lst->flags)[0])) && lst->width--;

	if ((lst->flags[0] == ' ' && lst->flags[1] == '#' && digit != 0))// || (lst->spec == 'p'))
		len += (lst->spec == 'X') ? (ft_print_str("0X", -1)) : (ft_print_str("0x", -1));
	
	while (lst->precision != -1 && lst->precision > 0)								//precision
		(len += ft_print_char('0')) && lst->precision--;
	

	len += (lst->spec == 'X') ? ft_print_x_digit(digit, lst, "0123456789ABCDEF") : ft_print_x_digit(digit, lst, "0123456789abcdef");
	// if (lst->spec == 'X')
	// 	len += ft_print_x_digit(digit, lst, "0123456789ABCDEF");
	// else
	// 	len += ft_print_x_digit(digit, lst, "0123456789abcdef");


	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(len += ft_print_char(' ')) && lst->width--;
	return (len);
}




int			ft_hendling_x(t_list *lst, void *digit)
{
	if (lst->j)
		return (ft_hend_x_digit(lst, (uintmax_t)digit));
	else if (lst->ll)
		return (ft_hend_x_digit(lst, (unsigned long long)digit));
	else if (lst->z)
		return (ft_hend_x_digit(lst, (size_t)digit));
	else if (lst->l)
		return (ft_hend_x_digit(lst, (unsigned long)digit));
	else if (lst->h)
		return (ft_hend_x_digit(lst, (unsigned short)digit));
	else if (lst->hh)
		return (ft_hend_x_digit(lst, (unsigned char)digit));
	else
		return (ft_hend_x_digit(lst, (unsigned int)digit));
}
