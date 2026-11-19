/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:57:45 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:36:22 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strlen
 *
 *	Compares ft_strlen with the libc strlen.
 *	Cases tested :
 *	1. empty string;
 *	2. single char;
 *	3. normal string with char;
 *	4. \0 in the middle : stops at the first \0;
 *	5. special characters (\t, \n);
 *	6. long string (9999 chars);
 *	NULL is not tested : the libc strlen crashes too.
 */

#include "../tester.h"

void	ft_strlen_test(void)
{
	char	*tests[] = {"", "a", "hello world", "abc\0def", "42\t\n", NULL};
	char	long_str[10000];
	int		i;

	i = 0;
	memset(long_str, 'a', 9999);
	long_str[9999] = '\0';
	while (tests[i] != NULL)
	{
		if (ft_strlen(tests[i]) != strlen(tests[i]))
		{
			write(1, "ft_strlen : KO\n", 15);
			return ;
		}
		i++;
	}
	if (ft_strlen(long_str) != strlen(long_str))
	{
		write(1, "ft_strlen : KO\n", 15);
		return ;
	}
	write(1, "ft_strlen : OK\n", 15);
}
