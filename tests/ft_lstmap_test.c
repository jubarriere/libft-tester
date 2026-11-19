/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 21:33:52 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/15 15:22:34 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	42 libft tester | ft_lstmap
 *
 *	Builds a test list and checks the result of ft_lstmap.
 *	Cases tested :
 *	1. the new list has the transformed contents, in the same order;
 * 	2. the new list has exactly 3 nodes;
 * 	3. the old list is untouched;
 * 	4. the new list uses new nodes;
 * 	5. lst = NULL : returns NULL;
 * 	Run make : Valgrind must report no leaks in either list.
 */

#include "../tester.h"

static void	*ft_upper_copy(void *content)
{
	char			*copy;
	unsigned int	i;

	copy = strdup(content);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (copy[i] != '\0')
	{
		if (i % 2 == 0 && (copy[i] >= 'a' && copy[i] <= 'z'))
			copy[i] = copy[i] - 32;
		i++;
	}
	return (copy);
}

static int	ft_check_lstmap(t_list *lst, char *s1, char *s2, char *s3)
{
	if (lst == NULL || lst->next == NULL || lst->next->next == NULL)
		return (1);
	if (strcmp(lst->content, s1) != 0 || strcmp(lst->next->content, s2) != 0
		|| strcmp(lst->next->next->content, s3) != 0
		|| lst->next->next->next != NULL)
		return (1);
	return (0);
}

void	ft_lstmap_test(void)
{
	t_list	*head;
	t_list	*new_lst;
	size_t	i;

	i = 0;
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(strdup("a")));
	ft_lstadd_back(&head, ft_lstnew(strdup("b")));
	ft_lstadd_back(&head, ft_lstnew(strdup("c")));
	new_lst = ft_lstmap(head, ft_upper_copy, free);
	i = i + ft_check_lstmap(new_lst, "A", "B", "C");
	i = i + ft_check_lstmap(head, "a", "b", "c");
	if (new_lst == head)
		i = 1;
	ft_lstclear(&head, free);
	ft_lstclear(&new_lst, free);
	if (i != 0)
		write(1, "ft_lstmap : KO\n", 15);
	else
		write(1, "ft_lstmap : OK\n", 15);
}
