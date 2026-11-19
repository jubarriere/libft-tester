/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:12:43 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/04 22:15:30 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_tolower
 *
 *	Compares ft_tolower with the libc tolower for every value from
		-1 (EOF) to 255.
 *	Characters outside the letter range must be returned unchanged.
 */

#include "../tester.h"

void	ft_tolower_test(void)
{
	int	i;

	i = -1;
	while (i <= 255)
	{
		if (ft_tolower(i) != tolower(i))
		{
			write(1, "ft_tolower : KO\n", 16);
			return ;
		}
		i++;
	}
	write(1, "ft_tolower : OK\n", 16);
}
