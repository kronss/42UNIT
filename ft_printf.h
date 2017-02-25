/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:00:15 by ochayche          #+#    #+#             */
/*   Updated: 2017/01/20 17:00:16 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** conversions: % s S p d D i o O u U x X c C
**
** # 0 - + space
** the minimum field-width // 20
** precision // .10
** hh, h, l, ll, j, z
**
**[1] = '#';
**[2] = '0';
**[3] = '-';
**[4] = '+';
**[5] = ' ';
*/

	// printf("size precision (%d)\n", lst->precision);
	// printf("size size (%d)\n", lst->size);
	// printf("size width (%d)\n", lst->width);


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>

#define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_list
{
	char		*flags;
	short		width;
	short		precision;
	char		hh;
	char		h;
	char		l;
	char		z;
	char		ll;
	char		j;
	char		spec;
	short		size;
}				t_list;

int				ft_hendling_char(t_list *lst, void *c);
int				ft_hendling_str(t_list *lst, void *str);
int				ft_hendling_digit(t_list *lst, void *digit);
int				ft_hendling_unsigned_digit(t_list *lst, void *digit);
int				ft_hendling_x(t_list *lst, void *digit);
int				ft_hendling_o(t_list *lst, void *digit);
int				ft_hendling_ptr(t_list *lst, void *digit);
int				ft_print_char(int c);
int				ft_print_str(char *str, int precision);
char			ft_print_wchar(wchar_t wc);
int				ft_print_wstr(wchar_t *wstr, int precision);
int				ft_out(t_list *list, va_list va);
int				ft_look_conversion(char **fmt, va_list va);
char			ft_strchr_f(char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *src);
int				ft_atoi_f(char **str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strlen(const char *s);
int				ft_print_percent(t_list *lst, char c);
int				ft_printf(char *fmt, ...);

#endif
