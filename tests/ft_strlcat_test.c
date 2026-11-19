/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:17:32 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 17:40:44 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strlcat
 *
 *	Compares ft_strlcat with the libc strlcat.
 *	Cases tested :
 *	1. size larger than dst + src;
 *	2. size exactly fits src + dst and \0;
 *	3. truncation : size one byte short;
 *	4. truncation : size smaller than dst + src;
 *	5. size = dst + 1 : only \0 , nothing appended;
 *	6. size = dst : nothing appended;
 *	7. size smaller than dst : nothing appended;
 *	8. size = 0, dst unchanged;
 *	9. src empty;
 *	10. dst empty;
 *	11. dst empty, size smaller than src;
 *	12. dst and src empty;
 *	13. dst and src empty, size = 0;
 */

#include "../tester.h"

static int	ft_check_strlcat(char *init, char *src, size_t size)
{
	size_t	ft_ret;
	size_t	libc_ret;
	char	ft_dst[50];
	char	libc_dst[50];

	strcpy(ft_dst, init);
	strcpy(libc_dst, init);
	ft_ret = ft_strlcat(ft_dst, src, size);
	libc_ret = strlcat(libc_dst, src, size);
	if (strcmp(ft_dst, libc_dst) != 0 || ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_strlcat_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strlcat("hello", " world", 50);
	i = i + ft_check_strlcat("hello", " world", 12);
	i = i + ft_check_strlcat("hello", " world", 11);
	i = i + ft_check_strlcat("hello", " world", 8);
	i = i + ft_check_strlcat("hello", " world", 6);
	i = i + ft_check_strlcat("hello", " world", 5);
	i = i + ft_check_strlcat("hello", " world", 3);
	i = i + ft_check_strlcat("hello", " world", 0);
	i = i + ft_check_strlcat("hello", "", 50);
	i = i + ft_check_strlcat("", " world", 50);
	i = i + ft_check_strlcat("", " world", 3);
	i = i + ft_check_strlcat("", "", 50);
	i = i + ft_check_strlcat("", "", 0);
	if (i != 0)
		write(1, "ft_strlcat : KO\n", 16);
	else
		write(1, "ft_strlcat : OK\n", 16);
}
