/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:39:16 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:35:47 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	ft_isprint_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_isprint(i) != 0 && ft_isprint(i) != 1)
		{
			write(1, "ft_isprint : KO\n", 16);
			return ;
		}
		if (ft_isprint(i) == 0 && isprint(i) != 0)
		{
			write(1, "ft_isprint : KO\n", 16);
			return ;
		}
		if (ft_isprint(i) != 0 && isprint(i) == 0)
		{
			write(1, "ft_isprint : KO\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_isprint : OK\n", 16);
}
