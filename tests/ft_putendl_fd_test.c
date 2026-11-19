/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:34:59 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 17:36:43 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_putendl_fd
 *
 *	Writes in test.txt with ft_putendl_fd, reads it back and compares
 *	with the expected string followed by \n. test.txt is deleted at the end.
 *	Cases tested :
 *	1. normal string, followed by \n;
 * 	2. empty string : \n only;
 * 	3. special character;
 *	4. \0 in the middle : stops there;
 *	5. bytes > 127;
 *	6. NULL : nothing written, no crash;
 */

#include "../tester.h"

static int	ft_check_putendl_fd(char *s, char *expected)
{
	char	buf[100];
	int		fd;
	ssize_t	n_read;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_putendl_fd(s, fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	n_read = read(fd, buf, 99);
	if (n_read < 0)
		return (1);
	buf[n_read] = '\0';
	if (strcmp(buf, expected) != 0)
		return (1);
	return (0);
}

void	ft_putendl_fd_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_putendl_fd("hello", "hello\n");
	i = i + ft_check_putendl_fd("", "\n");
	i = i + ft_check_putendl_fd("h\tell\no", "h\tell\no\n");
	i = i + ft_check_putendl_fd("hell\0o", "hell\n");
	i = i + ft_check_putendl_fd("\200\377", "\200\377\n");
	i = i + ft_check_putendl_fd(NULL, "");
	unlink("test.txt");
	if (i != 0)
		write(1, "ft_putendl_fd : KO\n", 19);
	else
		write(1, "ft_putendl_fd : OK\n", 19);
}
