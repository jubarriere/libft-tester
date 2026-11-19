/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:10:54 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:45:04 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_isascii
 *
 *	Compares ft_isascii with the libc isascii
 *	for every value from -1 (EOF) to 255.
 *	Only checks whether both results are zero or non-zeros :
 *	the libc may return any non-zero value for "true".
 */

#include "../tester.h"

void	ft_isascii_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_isascii(i) != 0 && ft_isascii(i) != 1)
		{
			write(1, "ft_isascii : KO\n", 16);
			return ;
		}
		if (ft_isascii(i) == 0 && isascii(i) != 0)
		{
			write(1, "ft_isascii : KO\n", 16);
			return ;
		}
		if (ft_isascii(i) != 0 && isascii(i) == 0)
		{
			write(1, "ft_isascii : KO\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_isascii : OK\n", 16);
}
