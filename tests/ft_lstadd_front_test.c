/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:01:13 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 18:37:45 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstadd_front
 *
 *	Builds a test list and checks the result of ft_lstadd_front.
 *	Cases tested :
 *	1. adding to an empty list (first call);
 * 	2. adding in front of an existing list;
 * 	3. final order of the nodes;
 */

#include "../tester.h"

void	ft_lstadd_front_test(void)
{
	t_list	*head;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	size_t	i;

	ft_create_nodes(&head, &node_a, &node_b, &node_c);
	ft_lstadd_front(&head, node_c);
	ft_lstadd_front(&head, node_b);
	ft_lstadd_front(&head, node_a);
	i = 0;
	if (head != node_a || node_a->next != node_b || node_b->next != node_c
		|| node_c->next != NULL)
		i = 1;
	ft_free_nodes(node_a, node_b, node_c);
	if (i != 0)
		write(1, "ft_lstadd_front : KO\n", 21);
	else
		write(1, "ft_lstadd_front : OK\n", 21);
}
