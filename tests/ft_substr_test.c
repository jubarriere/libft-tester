/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:32:09 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/11 17:01:16 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_substr
 *
 *	Compares ft_substr with the expected result written by hand.
 *	Cases tested :
 *	1. normal sub-string;
 *	2. start at index 0;
 *	3. whole string;
 *	4. len larger than what remains;
 *	5. last char;
 *	6. start = lenght : empty string;
 *	7. start after the end : empty string;
 *	8. len = 0 : empty string;
 *	9. empty string;
 *	10. s = NULL, returns : NULL;
 */

#include "../tester.h"

static int	ft_check_substr(char const *s, unsigned int start, size_t len,
		char *expected)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_substr(s, start, len);
	if (ft_ret == NULL)
		return (1);
	if (strcmp(ft_ret, expected) != 0)
		result = 1;
	free(ft_ret);
	return (result);
}

static int	ft_check_substr_null(void)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_substr(NULL, 0, 5);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	return (result);
}

void	ft_substr_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_substr("hello world", 6, 5, "world");
	i = i + ft_check_substr("hello world", 0, 5, "hello");
	i = i + ft_check_substr("hello", 0, 5, "hello");
	i = i + ft_check_substr("hello world", 6, 100, "world");
	i = i + ft_check_substr("hello", 4, 1, "o");
	i = i + ft_check_substr("hello", 5, 5, "");
	i = i + ft_check_substr("hello", 100, 4, "");
	i = i + ft_check_substr("hello world", 6, 0, "");
	i = i + ft_check_substr("", 0, 5, "");
	i = i + ft_check_substr_null();
	if (i != 0)
		write(1, "ft_substr : KO\n", 15);
	else
		write(1, "ft_substr : OK\n", 15);
}
