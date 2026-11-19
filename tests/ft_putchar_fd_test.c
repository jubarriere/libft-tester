/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:01:58 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 17:35:47 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_putchar_fd
 *
 *	Writes in test.txt with ft_putchar_fd, reads it back and checks that
 *	exactly 1 byte was written, equal to c. test. txt  is deleted at the end.
 *	Cases tested :
 *	1. normal char;
 * 	2. new line;
 * 	3. null char : 1 byte written;
 *	4. byte > 127;
 */

#include "../tester.h"

static int	ft_check_putchar_fd(char c)
{
	int		fd;
	char	buf[10];
	ssize_t	n_read;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putchar_fd(c, fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	n_read = read(fd, buf, 10);
	close(fd);
	if (n_read != 1 || buf[0] != c)
		return (1);
	return (0);
}

void	ft_putchar_fd_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_putchar_fd('a');
	i = i + ft_check_putchar_fd('\n');
	i = i + ft_check_putchar_fd('\0');
	i = i + ft_check_putchar_fd('\200');
	unlink("test.txt");
	if (i != 0)
		write(1, "ft_putchar_fd : KO\n", 19);
	else
		write(1, "ft_putchar_fd : OK\n", 19);
}
