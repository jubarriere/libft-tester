/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:39:19 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/19 00:37:35 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strtrim
 *
 *	Compares ft_strtrim with the expected result written by hand.
 *	Cases tested :
 *	1. set at start and end;
 *	2. several chars in set;
 *	3. set in the middle is kept;
 *	4. nothing to trim;
 *	5. set only at start;
 *	6. set only at end;
 *	7. only set chars : return ("");
 *	8. empty string;
 *	9. empty separator set, copy of s1;
 *	10. single char, in set;
 *	11. s1 = NULL, set = NULL, both = NULL
 */

#include "../tester.h"

static int	ft_check_strtrim(char const *s1, char const *set, char *expected)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strtrim(s1, set);
	if (ft_ret == NULL)
		result = 1;
	else if (strcmp(ft_ret, expected) != 0)
		result = 1;
	free(ft_ret);
	return (result);
}

static int	ft_check_strtrim_null(void)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strtrim(NULL, " ");
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	ft_ret = ft_strtrim("hello", NULL);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	ft_ret = ft_strtrim(NULL, NULL);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	return (result);
}

void	ft_strtrim_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strtrim("  hello  ", " ", "hello");
	i = i + ft_check_strtrim("xx  hello  xx", "x ", "hello");
	i = i + ft_check_strtrim("hello world", " ", "hello world");
	i = i + ft_check_strtrim("hello", " ", "hello");
	i = i + ft_check_strtrim("xxhello", "x", "hello");
	i = i + ft_check_strtrim("helloxx", "x", "hello");
	i = i + ft_check_strtrim("xxxx", "x", "");
	i = i + ft_check_strtrim("", " ", "");
	i = i + ft_check_strtrim("  hello  ", "", "  hello  ");
	i = i + ft_check_strtrim("h", "h", "");
	i = i + ft_check_strtrim_null();
	if (i != 0)
		write(1, "ft_strtrim : KO\n", 16);
	else
		write(1, "ft_strtrim : OK\n", 16);
}
