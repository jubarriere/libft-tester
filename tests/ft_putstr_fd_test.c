/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:22:10 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 17:36:05 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_putstr_fd
 *
 *	Writes in test.txt with ft_putstr_fd, reads it back and
 *	compares with the expected string. test.txt is deleted at the end.
 *	Cases tested :
 *	1. normal string;
 * 	2. empty string : nothing written;
 * 	3. special characters;
 *	4. \0 in the middle : stops there;
 *	5. bytes > 127;
 *	6. NULL : nothing written, no crash;
 */

#include "../tester.h"

static int	ft_check_putstr_fd(char *s, char *expected)
{
	int		fd;
	char	buf[100];
	ssize_t	n_read;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putstr_fd(s, fd);
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

void	ft_putstr_fd_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_putstr_fd("hello", "hello");
	i = i + ft_check_putstr_fd("", "");
	i = i + ft_check_putstr_fd("h\tell\no", "h\tell\no");
	i = i + ft_check_putstr_fd("hell\0o", "hell");
	i = i + ft_check_putstr_fd("\200\377", "\200\377");
	i = i + ft_check_putstr_fd(NULL, "");
	unlink("test.txt");
	if (i != 0)
		write(1, "ft_putstr_fd : KO\n", 18);
	else
		write(1, "ft_putstr_fd : OK\n", 18);
}
