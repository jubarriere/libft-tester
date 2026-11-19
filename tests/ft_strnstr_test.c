/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:28:35 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/11 11:49:39 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strnstr
 *
 *	Compares ft_strnstr with the expected position written by hand.
 *	(no strnstr in the Linux libc)
 *	Cases tested :
 *	1. little found in the middle;
 *	2. little go past len : NULL;
 *	3. little fits exactly in len;
 *	4. little not found : NULL;
 *	5. several occurences: find the first one;
 *	6. little at the very end of big;
 *	7. partial match first, then the real match
 *	8. little empty : returns big;
 *	9. little empty : n = 0;
 *	10. n = 0, little not empty : NULL;
 *	11. big empty;
 *	12. little longer than big;
 *	13. n larger than big;
 */

#include "../tester.h"

static int	ft_check_strnstr(const char *big, const char *little, size_t n,
		int pos)
{
	char	*ft_ret;

	ft_ret = ft_strnstr(big, little, n);
	if ((pos == -1 && ft_ret != NULL) || (pos != -1 && ft_ret != big + pos))
		return (1);
	else
		return (0);
}

void	ft_strnstr_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strnstr("hello world", "world", 11, 6);
	i = i + ft_check_strnstr("hello world", "world", 10, -1);
	i = i + ft_check_strnstr("hello world", "hello", 5, 0);
	i = i + ft_check_strnstr("hello world", "abc", 11, -1);
	i = i + ft_check_strnstr("hello hello", "hello", 11, 0);
	i = i + ft_check_strnstr("hello", "lo", 5, 3);
	i = i + ft_check_strnstr("aaab", "aab", 4, 1);
	i = i + ft_check_strnstr("hello world", "", 11, 0);
	i = i + ft_check_strnstr("hello world", "", 0, 0);
	i = i + ft_check_strnstr("hello world", "hello", 0, -1);
	i = i + ft_check_strnstr("", "hello", 5, -1);
	i = i + ft_check_strnstr("hello", "hello world", 11, -1);
	i = i + ft_check_strnstr("abc", "c", 100, 2);
	if (i != 0)
		write(1, "ft_strnstr : KO\n", 16);
	else
		write(1, "ft_strnstr : OK\n", 16);
}
