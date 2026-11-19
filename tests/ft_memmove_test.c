/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:55:09 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/10 17:09:48 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_memmove
 *
 *	Compares ft_memmove with the libc memmove.
 *	Cases tested :
 *	1. shift left , no overlaps;
 *	2. shift right, no overlaps;
 *	3. shift left, overlap;
 *	4. shift right, overlap;
 *	5. shift left by 1, whole buffer;
 *	6. shift right by 1, whole buffer;
 *	7. dst = src, no move;
 *	8. n = 0, no move;
 *	9. n = 1, shift left;
 *	10. n = 1, shift right;
 *	11. shift right, end last byte;
 */

#include "../tester.h"

static int	ft_check_memmove(size_t dst_pos, size_t src_pos, size_t n)
{
	unsigned char	ft_buf[50];
	unsigned char	libc_buf[50];
	void			*ft_ret;

	memcpy(ft_buf, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM", 50);
	memcpy(libc_buf, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM", 50);
	ft_ret = ft_memmove(ft_buf + dst_pos, ft_buf + src_pos, n);
	memmove(libc_buf + dst_pos, libc_buf + src_pos, n);
	if (ft_ret != ft_buf + dst_pos || memcmp(ft_buf, libc_buf, 50) != 0)
		return (1);
	else
		return (0);
}

void	ft_memmove_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_memmove(0, 10, 10);
	i = i + ft_check_memmove(10, 0, 10);
	i = i + ft_check_memmove(0, 5, 10);
	i = i + ft_check_memmove(5, 0, 10);
	i = i + ft_check_memmove(1, 0, 49);
	i = i + ft_check_memmove(0, 1, 49);
	i = i + ft_check_memmove(10, 10, 10);
	i = i + ft_check_memmove(5, 0, 0);
	i = i + ft_check_memmove(0, 1, 1);
	i = i + ft_check_memmove(1, 0, 1);
	i = i + ft_check_memmove(35, 40, 10);
	if (i != 0)
		write(1, "ft_memmove : KO\n", 16);
	else
		write(1, "ft_memmove : OK\n", 16);
}
