/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:05:27 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 14:50:24 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strlcpy
 *
 *	Compares ft_strlcpy with the libc strlcpy.
 *	Cases tested :
 *	1. size larger than src;
 *	2. size exactly fits src and its \0;
 *	3. truncation : size one byte short than src;
 *	4. truncation : size smaller than src;
 *	5. size = 1 : only \0 is written;
 *	6. size = 0 : dst unchanged;
 *	7. src empty;
 *	8. src empty, size = 0;
 */

#include "../tester.h"

static int	ft_check_strlcpy(const char *src, size_t size)
{
	char	ft_dst[50];
	char	libc_dst[50];
	size_t	ft_ret;
	size_t	libc_ret;

	memset(ft_dst, 'x', 50);
	memset(libc_dst, 'x', 50);
	ft_ret = ft_strlcpy(ft_dst, src, size);
	libc_ret = strlcpy(libc_dst, src, size);
	if (memcmp(ft_dst, libc_dst, 50) != 0 || ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_strlcpy_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strlcpy("hello", 50);
	i = i + ft_check_strlcpy("hello", 6);
	i = i + ft_check_strlcpy("hello", 5);
	i = i + ft_check_strlcpy("hello", 3);
	i = i + ft_check_strlcpy("hello", 1);
	i = i + ft_check_strlcpy("hello", 0);
	i = i + ft_check_strlcpy("", 50);
	i = i + ft_check_strlcpy("", 0);
	if (i != 0)
		write(1, "ft_strlcpy : KO\n", 16);
	else
		write(1, "ft_strlcpy : OK\n", 16);
}
