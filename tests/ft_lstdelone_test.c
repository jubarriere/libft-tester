/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:11:53 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 19:41:47 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstdelone
 *
 *	Builds a test list and checks the result of ft_lstdelone.
 *	Cases tested :
 *	1. deleting a node in the middle : neighbours untouched;
 * 	2. deleting the remaining nodes;
 * 	3. node = NULL : no crash;
 * 	Run make : Valgrind must report no leaks or invalid reads.
 */

#include "../tester.h"

void	ft_lstdelone_test(void)
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
	node_a->next = node_c;
	ft_lstdelone(node_b, free);
	if (node_a->next != node_c || node_c->next != NULL)
		i = 1;
	ft_lstdelone(node_a, free);
	ft_lstdelone(node_c, free);
	ft_lstdelone(NULL, free);
	if (i != 0)
		write(1, "ft_lstdelone : KO\n", 18);
	else
		write(1, "ft_lstdelone : OK\n", 18);
}
