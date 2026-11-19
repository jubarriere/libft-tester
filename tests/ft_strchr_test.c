/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:11:53 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 19:05:46 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_strchr
 *
 *	Compares ft_strchr with the libc strchr.
 *	Cases tested :
 *	1. c in first position;
 *	2. c in middle position;
 *	3. several occurences, must find the first one;
 *	4. c not found : NULL;
 *	5. c = '\0' : must find the adresse of the final \0;
 *	6. empty string;
 *	7. c > 255, one byte kept
 */

#include "../tester.h"

static int	ft_check_strchr(const char *s, int c)
{
	const char	*ft_ret;
	const char	*libc_ret;

	ft_ret = ft_strchr(s, c);
	libc_ret = strchr(s, c);
	if (ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_strchr_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_strchr("hello", 'h');
	i = i + ft_check_strchr("helo", 'l');
	i = i + ft_check_strchr("hello", 'l');
	i = i + ft_check_strchr("hello", 'u');
	i = i + ft_check_strchr("hello", '\0');
	i = i + ft_check_strchr("", 'h');
	i = i + ft_check_strchr("hello", 256 + 'h');
	if (i != 0)
		write(1, "ft_strchr : KO\n", 15);
	else
		write(1, "ft_strchr : OK\n", 15);
}
