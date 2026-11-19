/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:49:13 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/18 22:17:16 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strrchr
 *
 *	Compares ft_strrchr with the libc strrchr.
 *	Cases tested :
 *	1. c in last position;
 *	2. c in first position;
 *	3. c in middle position;
 *	4. several occurences, must find the last one;
 *	5. c not found : NULL;
 *	6. c = '\0' : must find the adress of the final \0;
 *	7. empty string;
 *	8. c > 255, one byte kept
 */

#include "../tester.h"

static int	ft_check_strrchr(const char *s, int c)
{
	const char	*ft_ret;
	const char	*libc_ret;

	ft_ret = ft_strrchr(s, c);
	libc_ret = strrchr(s, c);
	if (ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_strrchr_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strrchr("hello", 'o');
	i = i + ft_check_strrchr("hello", 'h');
	i = i + ft_check_strrchr("helo", 'l');
	i = i + ft_check_strrchr("hello", 'l');
	i = i + ft_check_strrchr("hello", 'u');
	i = i + ft_check_strrchr("hello", '\0');
	i = i + ft_check_strrchr("", 'h');
	i = i + ft_check_strrchr("hello", 256 + 'h');
	if (i != 0)
		write(1, "ft_strrchr : KO\n", 16);
	else
		write(1, "ft_strrchr : OK\n", 16);
}
