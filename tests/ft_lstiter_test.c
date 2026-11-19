/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:00:37 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 20:20:22 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstiter
 *
 *	Builds a test list and checks the result of ft_lstiter.
 *	Cases tested :
 *	1. every node is modified, including the last one;
 * 	2. lst = NULL : no crash;
 * 	3. f = NULL : no crash;
 */

#include "../tester.h"

static void	ft_upper_content(void *content)
{
	char			*str;
	unsigned int	i;

	str = (char *)content;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		i++;
	}
}

void	ft_lstiter_test(void)
{
	t_list	*head;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	size_t	i;

	i = 0;
	ft_create_nodes_alloc(&head, &node_a, &node_b, &node_c);
	ft_lstadd_back(&head, node_a);
	ft_lstadd_back(&head, node_b);
	ft_lstadd_back(&head, node_c);
	ft_lstiter(head, ft_upper_content);
	if (strcmp(node_a->content, "A") != 0 || strcmp(node_b->content, "B") != 0
		|| strcmp(node_c->content, "C") != 0)
		i = 1;
	ft_lstiter(NULL, ft_upper_content);
	ft_lstiter(head, NULL);
	ft_lstclear(&head, free);
	if (i != 0)
		write(1, "ft_lstiter : KO\n", 16);
	else
		write(1, "ft_lstiter : OK\n", 16);
}
