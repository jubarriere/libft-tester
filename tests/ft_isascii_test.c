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
