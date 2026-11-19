/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:11:29 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/18 23:09:42 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_itoa
 *
 *	Compares ft_itoa with the expected result written by hand.
 *	Cases tested :
 *	1. positive number;
 * 	2. negative number;
 * 	3. zero;
 *	4. single digit;
 *	5. power of 10;
 *	6. -1;
 *	7. INT_MAX;
 *	8. INT_MIN;
 */

#include "../tester.h"

static int	ft_check_itoa(int n, char *expected)
{
	char	*ft_ret;
	int		result;

	result = 0;
	ft_ret = ft_itoa(n);
	if (ft_ret == NULL)
		return (1);
	if (strcmp(ft_ret, expected) != 0)
		result = 1;
	free(ft_ret);
	return (result);
}

void	ft_itoa_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_itoa(42, "42");
	i = i + ft_check_itoa(-42, "-42");
	i = i + ft_check_itoa(0, "0");
	i = i + ft_check_itoa(7, "7");
	i = i + ft_check_itoa(10, "10");
	i = i + ft_check_itoa(-1, "-1");
	i = i + ft_check_itoa(2147483647, "2147483647");
	i = i + ft_check_itoa(-2147483648, "-2147483648");
	if (i != 0)
		write(1, "ft_itoa : KO\n", 13);
	else
		write(1, "ft_itoa : OK\n", 13);
}
