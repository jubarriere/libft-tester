/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:44:10 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 20:09:38 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_striteri
 *
 *	Compares ft_striteri with the expected result written by hand.
 *	Cases tested :
 *	1. normal string;
 * 	2. empty string
 * 	3. single char, index 0;
 *	4. already upper case : unchanged;
 *	5. f = NULL : string unchanged, no crash;
 *	6. s = NULL : no crash;
 */

#include "../tester.h"

static void	ft_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}

static int	ft_check_striteri(char *s, char *expected)
{
	char	buf[50];

	strcpy(buf, s);
	ft_striteri(buf, ft_upper_even);
	if (strcmp(buf, expected) != 0)
		return (1);
	else
		return (0);
}

static int	ft_check_striteri_null(void)
{
	char	buf[50];

	strcpy(buf, "hello");
	ft_striteri(buf, NULL);
	if (strcmp(buf, "hello") != 0)
		return (1);
	ft_striteri(NULL, ft_upper_even);
	return (0);
}

void	ft_striteri_test(void)
{
	size_t	i;

	i = 0;
	i = i + ft_check_striteri("hello", "HeLlO");
	i = i + ft_check_striteri("", "");
	i = i + ft_check_striteri("a", "A");
	i = i + ft_check_striteri("HELLO", "HELLO");
	i = i + ft_check_striteri_null();
	if (i != 0)
		write(1, "ft_striteri : KO\n", 17);
	else
		write(1, "ft_striteri : OK\n", 17);
}
