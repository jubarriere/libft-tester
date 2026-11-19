/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:25:46 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/13 20:41:42 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstnew
 *
 *	Builds a test list and checks the result of ft_lstnew.
 *	Cases tested :
 *	1. string literal as content;
 * 	2. int address as content;
 * 	3. NULL content : the node is still created;
 */

#include "../tester.h"

static int	ft_check_lstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (new_node == NULL)
		return (1);
	if (new_node->content != content || new_node->next != NULL)
	{
		free(new_node);
		return (1);
	}
	free(new_node);
	return (0);
}

void	ft_lstnew_test(void)
{
	size_t	i;
	int		n;

	i = 0;
	n = 42;
	i = i + ft_check_lstnew("hello");
	i = i + ft_check_lstnew(&n);
	i = i + ft_check_lstnew(NULL);
	if (i != 0)
		write(1, "ft_lstnew : KO\n", 15);
	else
		write(1, "ft_lstnew : OK\n", 15);
}
