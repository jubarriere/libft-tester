/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:15:23 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/18 23:48:01 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_split
 *
 *	Compares ft_split with the expected result written by hand.
 *	Cases tested :
 *	1. normal case;
 *	2. separator at start, at end and repeated;
 *	3. no separator, one word;
 *	4. empty string : only NULL;
 *	5. only separators : only NULL;
 *	6. other separator;
 *	7. c = '\0' : whole string as one word;
 *	8. single char word;
 *	9. single word surrounded by separators;
 *	10. NULL string;
 Run make : Valgrind must report no leaks.
*/

#include "../tester.h"

static void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_check_split(char const *s, char c, char **expected)
{
	char	**ft_ret;
	size_t	i;

	ft_ret = ft_split(s, c);
	if (ft_ret == NULL)
		return (1);
	i = 0;
	while (expected[i] != NULL)
	{
		if (ft_ret[i] == NULL || strcmp(ft_ret[i], expected[i]) != 0)
		{
			ft_free_tab(ft_ret);
			return (1);
		}
		i++;
	}
	if (ft_ret[i] != NULL)
	{
		ft_free_tab(ft_ret);
		return (1);
	}
	ft_free_tab(ft_ret);
	return (0);
}

void	ft_split_test(void)
{
	size_t	i;
	char	*expected1[] = {"hello", "world", NULL};
	char	*expected2[] = {"hello", NULL};
	char	*expected3[] = {NULL};
	char	*expected4[] = {"a", "b", "c", NULL};
	char	*expected5[] = {"a", NULL};

	i = 0;
	i = i + ft_check_split("hello world", ' ', expected1);
	i = i + ft_check_split("  hello   world  ", ' ', expected1);
	i = i + ft_check_split("hello", ' ', expected2);
	i = i + ft_check_split("", ' ', expected3);
	i = i + ft_check_split("     ", ' ', expected3);
	i = i + ft_check_split("a,b,c", ',', expected4);
	i = i + ft_check_split("hello\0", '\0', expected2);
	i = i + ft_check_split("a", ' ', expected5);
	i = i + ft_check_split("  a  ", ' ', expected5);
	if (ft_split(NULL, ' ') != NULL)
		i = 1;
	if (i != 0)
		write(1, "ft_split : KO\n", 14);
	else
		write(1, "ft_split : OK\n", 14);
}
