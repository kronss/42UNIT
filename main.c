/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 23:48:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/25 17:04:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     main(void)
{
	int a;
	int b;

	// char *str = "qwerty123 ///// ppp232";


	// a =    printf("хуй пизда [%d] [%40.18s]\n", 123, str);
	// b = ft_printf("хуй пизда [%d] [%40.18s]\n", 123, str);
	// printf("orig: %d\n", a);
	// printf("ft_p: %d\n", b);
	// printf("======================\n");
	// fflush(stdout);

	// a =    printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);
	// b = ft_printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);
	// printf("orig: %d\n", a);
	// printf("ft_p: %d\n", b);
	// printf("======================\n");
	// fflush(stdout);
	
	// int nbr = -1;
	// char *s = "LYDI";

	
	// b = ft_printf("ft_p[%s] [%d] [%p] [ [%%]\n", "bonjour ", 42,);
	// a =    printf("orig[%s] [%d] [%p] [%x] [%%]\n", "bonjour ", 42,);
	
	
	// printf("ft_p: [%d]\n", b);
	// printf("orig: [%d]\n", a);
	// printf("======================\n");
	// fflush(stdout);

	b = ft_printf("%20b\n");
	a =    printf("%20b\n");

	printf("ft_p: [%d]\n", b);
	printf("orig: [%d]\n", a);
	printf("======================\n");
	fflush(stdout);

	// b = ft_printf("ft_p[%o]\n", 0);
	// a =    printf("orig[%o]\n", 0);

	// printf("ft_p: [%d]\n", b);
	// printf("orig: [%d]\n", a);
	// printf("======================\n");
	// fflush(stdout);


    return (0);
}


// ft_printf("@moulitest: %#.o %#.0o", 0, 0);

// ft_printf("@moulitest: %s", NULL);         //   -> "@moulitest: (null)@moulitest: "


// 
