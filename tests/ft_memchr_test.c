/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:16:41 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 21:37:01 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_memchr
 *
 *	Compares ft_memchr with the libc memchr.
 *	Cases tested :
 *	1. c in first position;
 *	2. c in the middle;
 *	3. several occurences : must find the first one;
 *	4. c not found : NULL;
 *	5. c only after n : NULL;
 *	6. n = 0 : NULL;
 *	7. \0 in the middle : memchr must not stop;
 *	8. search for \0;
 *	9. c > 255 : only the low byte kept;
 *	10. byte > 127;
 */

#include "../tester.h"

static int	ft_check_memchr(const void *s, int c, size_t n)
{
	const void	*ft_ret;
	const void	*libc_ret;

	ft_ret = ft_memchr(s, c, n);
	libc_ret = memchr(s, c, n);
	if (ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_memchr_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_memchr("hello", 'h', 5);
	i = i + ft_check_memchr("helo", 'l', 4);
	i = i + ft_check_memchr("hello", 'l', 5);
	i = i + ft_check_memchr("hello", 'u', 5);
	i = i + ft_check_memchr("hello", 'o', 4);
	i = i + ft_check_memchr("hello", 'e', 0);
	i = i + ft_check_memchr("hel\0lo", 'e', 6);
	i = i + ft_check_memchr("hel\0lo", '\0', 6);
	i = i + ft_check_memchr("hello", 256 + 'l', 5);
	i = i + ft_check_memchr("ab\200cd", '\200', 5);
	if (i != 0)
		write(1, "ft_memchr : KO\n", 15);
	else
		write(1, "ft_memchr : OK\n", 15);
}
