/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:54:13 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 17:36:20 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_putnbr_fd
 *
 *	Writes in test.txt with ft_putnbr_fd, reads it back and compares with
 *	the expected number as text. test.txt is deleted at the end.
 *	Cases tested :
 *	1. positive number;
 * 	2. negative number;
 * 	3. zero;
 *	4. one digit;
 *	5. power of 10;
 *	6. -1;
 *	7. INT_MAX;
 *	8. INT_MIN;
 */

#include "../tester.h"

static int	ft_check_putnbr_fd(int n, char *expected)
{
	int		fd;
	char	buf[100];
	ssize_t	n_read;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(n, fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	n_read = read(fd, buf, 99);
	close(fd);
	if (n_read < 0)
		return (1);
	buf[n_read] = '\0';
	if (strcmp(buf, expected) != 0)
		return (1);
	return (0);
}

void	ft_putnbr_fd_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_putnbr_fd(42, "42");
	i = i + ft_check_putnbr_fd(-42, "-42");
	i = i + ft_check_putnbr_fd(0, "0");
	i = i + ft_check_putnbr_fd(7, "7");
	i = i + ft_check_putnbr_fd(10, "10");
	i = i + ft_check_putnbr_fd(-1, "-1");
	i = i + ft_check_putnbr_fd(2147483647, "2147483647");
	i = i + ft_check_putnbr_fd(-2147483648, "-2147483648");
	unlink("test.txt");
	if (i != 0)
		write(1, "ft_putnbr_fd : KO\n", 18);
	else
		write(1, "ft_putnbr_fd : OK\n", 18);
}
