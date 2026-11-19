/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:41:43 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/11 01:14:46 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strdup
 *
 *	Compares ft_strdup with the libc strdup.
 *	Cases tested :
 *	1. normal string;
 *	2. empty string;
 *	3. long string (9999 chars);
 *	4. \0 in the middle : copies the first part only;
 *	5. special characters;
 *	6. bytes > 127;
 */

#include "../tester.h"

static int	ft_check_strdup(const char *s)
{
	char	*ft_dup;
	char	*libc_dup;
	int		result;

	result = 0;
	ft_dup = ft_strdup(s);
	libc_dup = strdup(s);
	if (ft_dup == s)
	{
		free(libc_dup);
		return (1);
	}
	if ((libc_dup == NULL && ft_dup != NULL) || (libc_dup != NULL
			&& ft_dup == NULL) || (libc_dup != NULL && ft_dup != NULL
			&& strcmp(libc_dup, ft_dup) != 0))
		result = 1;
	free(ft_dup);
	free(libc_dup);
	return (result);
}

void	ft_strdup_test(void)
{
	size_t	i;
	char	long_str[10000];

	memset(long_str, 'x', 9999);
	long_str[9999] = '\0';
	i = 0;
	i = i + ft_check_strdup("hello");
	i = i + ft_check_strdup("");
	i = i + ft_check_strdup(long_str);
	i = i + ft_check_strdup("hel\0lo");
	i = i + ft_check_strdup("\t\n");
	i = i + ft_check_strdup("\200");
	if (i != 0)
		write(1, "ft_strdup : K0\n", 15);
	else
		write(1, "ft_strdup : OK\n", 15);
}
