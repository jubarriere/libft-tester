/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:29:59 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 21:09:50 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	ft_isalpha_test(void)
{
	int	i;
	
	i = -1;
	while (i <= 255)
	{
		if (ft_isalpha(i) != 1 && ft_isalpha(i) != 0)
		{
			write(1, "ft_isalpha : KO\n", 16);
			return ;
		}
		if (isalpha(i) == 0 && ft_isalpha(i) != 0)
		{
			write(1, "ft_isalpha : KO\n", 16);
			return ;	
		}
		if (isalpha(i) != 0 && ft_isalpha(i) == 0)
		{
			write(1, "ft_isalpha : KO\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_isalpha : OK\n", 16);
}
