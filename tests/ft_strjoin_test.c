/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:14:23 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/19 00:38:04 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strjoin
 *
 *	Compares ft_strjoin with the expected result written by hand.
 *	Cases tested :
 *	1. normal join str;
 *	2. s1 empty, return ("" not NULL);
 *	3. s2 empty, return ("" not NULL);
 *	4. both empty, return ("" not NULL);
 *	5. \0 in the middle of s1;
 *	6. start = lenght : empty string;
 *	7. start after the end : empty string;
 *	8. special chars and byte > 127;
 *	9. s1 = NULL, s2 = NULL, both NULL : returns NULL
 */

#include "../tester.h"

static int	ft_check_strjoin(char const *s1, char const *s2, char *expected)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strjoin(s1, s2);
	if (ft_ret == NULL)
		result = 1;
	else if (strcmp(ft_ret, expected) != 0)
		result = 1;
	free(ft_ret);
	return (result);
}

static int	ft_check_strjoin_null(void)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strjoin(NULL, "world");
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	ft_ret = ft_strjoin("hello", NULL);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	ft_ret = ft_strjoin(NULL, NULL);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	return (result);
}

void	ft_strjoin_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strjoin("hello", " world", "hello world");
	i = i + ft_check_strjoin("", "world", "world");
	i = i + ft_check_strjoin("hello", "", "hello");
	i = i + ft_check_strjoin("", "", "");
	i = i + ft_check_strjoin("hel\0lo", " world", "hel world");
	i = i + ft_check_strjoin("\t\n", "\200", "\t\n\200");
	i = i + ft_check_strjoin_null();
	if (i != 0)
		write(1, "ft_strjoin : KO\n", 16);
	else
		write(1, "ft_strjoin : OK\n", 16);
}
