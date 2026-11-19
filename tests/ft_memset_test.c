/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:02:15 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 14:29:22 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_memset
 *
 *	Compares ft_memset with the libc memset.
 *	Cases tested :
 *	1. fill whole buffer;
 *	2. one byte short : last byte must stay intact;
 *	3. partial fill;
 *	4. n = 1;
 *	5. n = 0 : buffer unchanged;
 *	6. c = 0;
 *	7. c = 127 (max signed char);
 *	8. c = 128 (max signed char + 1);
 *	9. c = 255 (max unsigned char);
 *	10. c > 255 only the low byte is kept
 *	11. c = 127 (max signed char);
 *	12. c < 0 : -1 becomes 0xFF;
 *	n larger than buffer is not tested : undefined behaviour.
 */

#include "../tester.h"

static int	ft_check_memset(int c, size_t n)
{
	unsigned char	libc_buf[200];
	unsigned char	ft_buf[200];
	void			*ft_ret;

	memset(ft_buf, 'x', 200);
	memset(libc_buf, 'x', 200);
	ft_ret = ft_memset(ft_buf, c, n);
	memset(libc_buf, c, n);
	if (ft_ret != ft_buf || memcmp(ft_buf, libc_buf, 200) != 0)
		return (1);
	return (0);
}

void	ft_memset_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_memset('A', 200);
	i = i + ft_check_memset('A', 199);
	i = i + ft_check_memset('A', 100);
	i = i + ft_check_memset('A', 1);
	i = i + ft_check_memset('A', 0);
	i = i + ft_check_memset(0, 200);
	i = i + ft_check_memset(127, 200);
	i = i + ft_check_memset(128, 200);
	i = i + ft_check_memset(255, 200);
	i = i + ft_check_memset(255, 200);
	i = i + ft_check_memset(255 + 'A', 200);
	i = i + ft_check_memset(-1, 200);
	if (i != 0)
		write(1, "ft_memset : KO\n", 15);
	else
		write(1, "ft_memset : OK\n", 15);
}
