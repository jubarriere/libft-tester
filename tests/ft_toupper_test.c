/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:04:30 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 22:12:28 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void	ft_toupper_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_toupper(i) != toupper(i))
		{
			write(1, "ft_toupper : K0\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_toupper : OK\n", 16);
}
