/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:41:45 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 22:22:58 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_atoi
 *
 *	Compares ft_atoi with the libc atoi.
 *	Cases tested :
 *	1. number positive;
 *	2. number negative;
 *	3. explicit + sign;
 *	4. zero;
 *	5. negative zero;
 *	6. leading zeros, positive number;
 *	7. leading spaces, positive number;
 *	8. whitespace types (\t \n \v \f \r), positive number;
 *	9. stops at the first non-digit;
 *	10. stops at a space between digits;
 *	11. no digit first : 0;
 *	12. double minus sign : 0;
 *	13. mixed signs : 0;
 *	14. space after the sign : 0;
 *	15. empty string : 0;
 *	16. INT_MAX;
 *	17. INT_MIN;
 */

#include "../tester.h"

static int	ft_check_atoi(const char *str)
{
	int	ft_ret;
	int	libc_ret;

	ft_ret = ft_atoi(str);
	libc_ret = atoi(str);
	if (ft_ret != libc_ret)
		return (1);
	else
		return (0);
}

void	ft_atoi_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_atoi("42");
	i = i + ft_check_atoi("-42");
	i = i + ft_check_atoi("+42");
	i = i + ft_check_atoi("0");
	i = i + ft_check_atoi("-0");
	i = i + ft_check_atoi("0042");
	i = i + ft_check_atoi("    42");
	i = i + ft_check_atoi("\t\n\v\f\r 42");
	i = i + ft_check_atoi("42abc");
	i = i + ft_check_atoi("4 2");
	i = i + ft_check_atoi("abc42");
	i = i + ft_check_atoi("--42");
	i = i + ft_check_atoi("+-42");
	i = i + ft_check_atoi("- 42");
	i = i + ft_check_atoi("");
	i = i + ft_check_atoi("2147483647");
	i = i + ft_check_atoi("-2147483648");
	if (i != 0)
		write(1, "ft_atoi : KO\n", 13);
	else
		write(1, "ft_atoi : OK\n", 13);
}
