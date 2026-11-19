/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:34:36 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 21:16:17 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_memcmp
 *
 *	Compares ft_memcmp with the libc memcmp.
 *	Cases tested :
 *	1. identical memory areas;
 *	2. different before n;
 *	3. different after n;
 *	4. n = 0, always 0;
 *	5. bytes > 127;
 *	6. different after \0 : memcmp must not stop at \0;
 *	7. n includes the final \0 : \0 compared with another char
 */

#include "../tester.h"

static int	ft_check_memcmp(const void *s1, const void *s2, size_t n)
{
	int	ft_ret;
	int	libc_ret;

	ft_ret = ft_memcmp(s1, s2, n);
	libc_ret = memcmp(s1, s2, n);
	if ((libc_ret > 0 && !(ft_ret > 0)) || (libc_ret < 0 && !(ft_ret < 0))
		|| (libc_ret == 0 && !(ft_ret == 0)))
		return (1);
	else
		return (0);
}

void	ft_memcmp_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_memcmp("hello", "hello", 5);
	i = i + ft_check_memcmp("hello", "hella", 5);
	i = i + ft_check_memcmp("hello", "hella", 4);
	i = i + ft_check_memcmp("hello", "hello", 0);
	i = i + ft_check_memcmp("\200", "a", 1);
	i = i + ft_check_memcmp("hell\0o", "hell\0a", 6);
	i = i + ft_check_memcmp("hello", "helloa", 6);
	if (i != 0)
		write(1, "ft_memcmp : KO\n", 15);
	else
		write(1, "ft_memcmp : OK\n", 15);
}
