/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:28:43 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/11 16:03:17 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strmapi
 *
 *	Compares ft_strmapi with the expected result written by hand.
 *	Cases tested :
 *	1. normal string;
 * 	2. empty str, return ("", not NULL);
 * 	3. single char, index 0;
 *	4. already upper case : unchanged;
 *	5. f = NULL and s = NULL : return (NULL);
 */

#include "../tester.h"

static char	ft_upper_even_mapi(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}

static int	ft_check_strmapi(char const *s, char *expected)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strmapi(s, ft_upper_even_mapi);
	if (ft_ret == NULL)
		return (1);
	if (strcmp(ft_ret, expected) != 0)
		result = 1;
	free(ft_ret);
	return (result);
}

static int	ft_check_strmapi_null(char *s)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_strmapi(s, NULL);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	ft_ret = ft_strmapi(NULL, ft_upper_even_mapi);
	if (ft_ret != NULL)
		result = 1;
	free(ft_ret);
	return (result);
}

void	ft_strmapi_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strmapi("hello", "HeLlO");
	i = i + ft_check_strmapi("", "");
	i = i + ft_check_strmapi("a", "A");
	i = i + ft_check_strmapi("HELLO", "HELLO");
	i = i + ft_check_strmapi_null("hello");
	if (i != 0)
		write(1, "ft_strmapi : KO\n", 16);
	else
		write(1, "ft_strmapi : OK\n", 16);
}
