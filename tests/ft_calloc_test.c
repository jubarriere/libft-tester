/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:53:47 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/11 00:36:47 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_calloc
 *
 *	Compares ft_calloc with the libc calloc.
 *	Cases tested :
 *	1. normal allocation;
 *	2. array of int;
 *	3. large allocation;
 *	4. n = 0;
 *	5. size = 0;
 *	6. both = 0;
 *	7. overflow (SIZE_MAX * 2) : must return (NULL);
 *	Run make : Valgrind must report leaks.
 */

#include "../tester.h"

static int	ft_check_calloc(size_t n, size_t size)
{
	void	*ft_ret;
	void	*libc_ret;
	int		result;

	ft_ret = ft_calloc(n, size);
	libc_ret = calloc(n, size);
	result = 0;
	if (size != 0 && n > SIZE_MAX / size)
	{
		if (ft_ret != NULL || libc_ret != NULL)
			result = 1;
	}
	else if ((ft_ret == NULL && libc_ret != NULL)
		|| (ft_ret != NULL && libc_ret == NULL))
		result = 1;
	else if (ft_ret != NULL
		&& memcmp(ft_ret, libc_ret, n * size) != 0)
		result = 1;
	free(ft_ret);
	free(libc_ret);
	return (result);
}

void	ft_calloc_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_calloc(10, 1);
	i = i + ft_check_calloc(5, sizeof(int));
	i = i + ft_check_calloc(1000, 1);
	i = i + ft_check_calloc(0, 1);
	i = i + ft_check_calloc(10, 0);
	i = i + ft_check_calloc(0, 0);
	i = i + ft_check_calloc(SIZE_MAX, 2);
	if (i != 0)
		write(1, "ft_calloc : KO\n", 15);
	else
		write(1, "ft_calloc : OK\n", 15);
}
