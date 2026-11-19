/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:11:42 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 15:33:15 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_memcpy
 *
 *	Compares ft_memcpy with the libc memcpy.
 *	Cases tested :
 *	1. copy including the final \0;
 *	2. copy without the final \0;
 *	3. partial copy;
 *	4. n = 1;
 *	5. n = 0 : dst unchanged;
 *	6. \0 in the middle : memcpy must not stop here;
 *	7. bytes > 127;
 *	8. empty src, only \0 copied;
 *	9. empty src, n = 0;
 */

#include "../tester.h"

static int	ft_check_memcpy(const void *src, size_t n)
{
	unsigned char	libc_dst[200];
	unsigned char	ft_dst[200];
	void			*ft_ret;

	memset(libc_dst, 'x', 200);
	memset(ft_dst, 'x', 200);
	ft_ret = ft_memcpy(ft_dst, src, n);
	memcpy(libc_dst, src, n);
	if (ft_ret != ft_dst || memcmp(ft_dst, libc_dst, 200) != 0)
		return (1);
	else
		return (0);
}

void	ft_memcpy_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_memcpy("hello", 6);
	i = i + ft_check_memcpy("hello", 5);
	i = i + ft_check_memcpy("hello", 3);
	i = i + ft_check_memcpy("hello", 1);
	i = i + ft_check_memcpy("hello", 0);
	i = i + ft_check_memcpy("hello\n word", 11);
	i = i + ft_check_memcpy("\200\377", 3);
	i = i + ft_check_memcpy("", 1);
	i = i + ft_check_memcpy("", 0);
	if (i != 0)
		write(1, "ft_memcpy : K0\n", 15);
	else
		write(1, "ft_memcpy : OK\n", 15);
}
