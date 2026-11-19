/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 22:04:27 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/09 22:14:50 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_bzero
 *
 *	Compares ft_bzero with the libc bzero.
 *	Cases tested :
 *	1. fill whole buffer;
 *	2. one byte short : last byte must stay intact;
 *	3. partial fill;
 *	4. n = 1;
 *	5. n = 0 : buffer unchanged;
 */

#include "../tester.h"

static int	ft_check_bzero(size_t n)
{
	unsigned char	ft_buf[200];
	unsigned char	libc_buf[200];

	memset(ft_buf, 'x', 200);
	memset(libc_buf, 'x', 200);
	ft_bzero(ft_buf, n);
	bzero(libc_buf, n);
	if (memcmp(ft_buf, libc_buf, 200) != 0)
		return (1);
	return (0);
}

void	ft_bzero_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_bzero(200);
	i = i + ft_check_bzero(199);
	i = i + ft_check_bzero(100);
	i = i + ft_check_bzero(1);
	i = i + ft_check_bzero(0);
	if (i != 0)
		write(1, "ft_bzero : KO\n", 14);
	else
		write(1, "ft_bzero : OK\n", 14);
}
