/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:55:52 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 19:10:34 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstadd_back
 *
 *	Builds a test list and checks the result of ft_lstadd_back.
 *	Cases tested :
 *	1. adding to an empty list (first call);
 * 	2. adding behind the last node of an existing list;
 * 	3. final order of the nodes;
 */

#include "../tester.h"

void	ft_lstadd_back_test(void)
{
	t_list	*head;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	size_t	i;

	i = 0;
	ft_create_nodes(&head, &node_a, &node_b, &node_c);
	ft_lstadd_back(&head, node_a);
	ft_lstadd_back(&head, node_b);
	ft_lstadd_back(&head, node_c);
	if (head != node_a || node_a->next != node_b || node_b->next != node_c
		|| node_c->next != NULL)
		i = 1;
	ft_free_nodes(node_a, node_b, node_c);
	if (i != 0)
		write(1, "ft_lstadd_back : KO\n", 20);
	else
		write(1, "ft_lstadd_back : OK\n", 20);
}
