/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:39:33 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/15 15:11:07 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstlast
 *
 *	Builds a test list and checks the result of ft_lstlast.
 *	Cases tested :
 *	1. list of 3 nodes : returns the last one;
 * 	2. empty list : NULL;
 */

#include "../tester.h"

void	ft_lstlast_test(void)
{
	t_list	*head;
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;
	size_t	i;

	i = 0;
	ft_create_nodes(&head, &node_a, &node_b, &node_c);
	ft_lstadd_front(&head, node_c);
	ft_lstadd_front(&head, node_b);
	ft_lstadd_front(&head, node_a);
	if (ft_lstlast(head) != node_c)
		i = 1;
	if (ft_lstlast(NULL) != NULL)
		i = 1;
	ft_free_nodes(node_a, node_b, node_c);
	if (i != 0)
		write(1, "ft_lstlast : KO\n", 16);
	else
		write(1, "ft_lstlast : OK\n", 16);
}
