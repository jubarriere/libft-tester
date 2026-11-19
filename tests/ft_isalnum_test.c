/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:46:35 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:34:41 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_isalnum
 *
 *	Compares ft_isalnum with the libc isalnum
 *	for every value from -1 (EOF) to 255.
 *	Only checks whether both results are zero or non-zeros :
 *	the libc may return any non-zero value for "true".
 */

#include "../tester.h"

void	ft_isalnum_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_isalnum(i) != 0 && ft_isalnum(i) != 1)
		{
			write(1, "ft_isalnum : K0\n", 16);
			return ;
		}
		if (ft_isalnum(i) != 0 && isalnum(i) == 0)
		{
			write(1, "ft_isalnum : K0\n", 16);
			return ;
		}
		if (ft_isalnum(i) == 0 && isalnum(i) != 0)
		{
			write(1, "ft_isalnum : K0\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_isalnum : OK\n", 16);
}
