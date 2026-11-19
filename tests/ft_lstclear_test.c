/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:42:55 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 20:00:16 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstclear
 *
 *	Builds a test list and checks the result of ft_lstclear.
 *	Cases tested :
 *	1. list of 3 nodes : head must be NULL after the call;
 * 	2. empty list : no crash;
 * 	3. lst = NULL : no crash;
 * 	Run make : Valgrind must report no leaks.
 */

#include "../tester.h"

void	ft_lstclear_test(void)
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
	ft_lstclear(&head, free);
	if (head != NULL)
		i = 1;
	ft_lstclear(&head, free);
	ft_lstclear(NULL, free);
	if (i != 0)
		write(1, "ft_lstclear : KO\n", 17);
	else
		write(1, "ft_lstclear : OK\n", 17);
}
