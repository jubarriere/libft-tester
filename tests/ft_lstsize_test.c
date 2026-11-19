/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:41:24 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 17:32:20 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstsize
 *
 *	Builds a test list and checks the result of ft_lstsize.
 *	Cases tested :
 *	1. empty list : 0;
 * 	2. one node : 1;
 * 	3. several nodes : 3;
 * 	4. starting in the middle of the list : 2;
 */

#include "../tester.h"

void	ft_lstsize_test(void)
{
	t_list	*head;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	size_t	i;

	i = 0;
	ft_create_nodes(&head, &node_a, &node_b, &node_c);
	if (ft_lstsize(head) != 0)
		i = 1;
	ft_lstadd_front(&head, node_c);
	if (ft_lstsize(head) != 1)
		i = 1;
	ft_lstadd_front(&head, node_b);
	ft_lstadd_front(&head, node_a);
	if (ft_lstsize(head) != 3)
		i = 1;
	if (ft_lstsize(node_b) != 2)
		i = 1;
	ft_free_nodes(node_a, node_b, node_c);
	if (i != 0)
		write(1, "ft_lstsize : KO\n", 16);
	else
		write(1, "ft_lstsize : OK\n", 16);
}
