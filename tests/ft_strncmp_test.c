/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:04:55 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 19:00:13 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strncmp
 *
 *	Compares ft_strncmp with the libc strncmp.
 *	Cases tested :
 *	1. identical strings;
 *	2. difference before n;
 *	3. difference after n : 0;
 *	4. n = 0 : always 0;
 *	5. s1 prefix of s2 : \0 compared with a letter;
 *	6. both empty;
 *	7. s1 empty;
 *	8. s2 empty;
 *	9. char > 127 : compared as unsigned char;
 *	10. difference after \0 : strncmp stops at \0, returns 0;
 *	11. n larger than the strings;
 */

#include "../tester.h"

static int	ft_check_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ft_ret;
	int	libc_ret;

	ft_ret = ft_strncmp(s1, s2, n);
	libc_ret = strncmp(s1, s2, n);
	if ((libc_ret == 0 && ft_ret != 0) || (libc_ret > 0 && !(ft_ret > 0))
		|| (libc_ret < 0 && !(ft_ret < 0)))
		return (1);
	else
		return (0);
}

void	ft_strncmp_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strncmp("hello", "hello", 5);
	i = i + ft_check_strncmp("hello", "helli", 5);
	i = i + ft_check_strncmp("hello", "helli", 4);
	i = i + ft_check_strncmp("hello", "hello", 0);
	i = i + ft_check_strncmp("abc", "abcd", 4);
	i = i + ft_check_strncmp("", "", 5);
	i = i + ft_check_strncmp("", "hello", 5);
	i = i + ft_check_strncmp("hello", "", 5);
	i = i + ft_check_strncmp("\200", "a", 1);
	i = i + ft_check_strncmp("abc\0d", "abc\0e", 5);
	i = i + ft_check_strncmp("hello", "helli", 100);
	if (i != 0)
		write(1, "ft_strncmp : KO\n", 16);
	else
		write(1, "ft_strncmp : OK\n", 16);
}
