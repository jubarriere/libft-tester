/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:14:35 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/14 19:23:59 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | lst utils
 *
 *	Helper functions shared by the lst testers.
 *	1. ft_create_nodes : create an empty head and 3 nodes a, b and c
 *	with string literals as contents.
 *	2. ft_create_nodes_alloc : same, with allocated contents (strdup)
 *	for the tests that free or modify the contents.
 *	3. ft_free_nodes : frees the 3 nodes created by ft_create_nodes,
 *	without their contents.
 */

#include "../tester.h"

void	ft_create_nodes(t_list **head, t_list **node_a, t_list **node_b,
		t_list **node_c)
{
	*head = NULL;
	*node_a = ft_lstnew("a");
	*node_b = ft_lstnew("b");
	*node_c = ft_lstnew("c");
}

void	ft_free_nodes(t_list *node_a, t_list *node_b, t_list *node_c)
{
	free(node_a);
	free(node_b);
	free(node_c);
}

void	ft_create_nodes_alloc(t_list **head, t_list **node_a, t_list **node_b,
		t_list **node_c)
{
	*head = NULL;
	*node_a = ft_lstnew(strdup("a"));
	*node_b = ft_lstnew(strdup("b"));
	*node_c = ft_lstnew(strdup("c"));
}
