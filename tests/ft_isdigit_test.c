/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:32:43 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:37:18 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	ft_isdigit_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_isdigit(i) != 0 && ft_isdigit(i) != 1)
		{
			write(1, "ft_isdigit : KO\n", 16);
			return ;
		}
		if (ft_isdigit(i) != 0 && isdigit(i) == 0)
		{
			write(1, "ft_isdigit : KO\n", 16);
			return ;
		}
		if (ft_isdigit(i) == 0 && isdigit(i) != 0)
		{
			write(1, "ft_isdigit : KO\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_isdigit : OK\n", 16); 
}
