/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julbarri <julbarri@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:02:46 by julbarri          #+#    #+#             */
/*   Updated: 2026/11/19 23:23:07 by julbarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <ctype.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft.h"

/* Part 1 - Libc functions */
void	ft_isalpha_test(void);
void	ft_isdigit_test(void);
void	ft_isalnum_test(void);
void	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_strlen_test(void);
void	ft_memset_test(void);
void	ft_bzero_test(void);
void	ft_memcpy_test(void);
void	ft_memmove_test(void);
void	ft_strlcpy_test(void);
void	ft_strlcat_test(void);
void	ft_toupper_test(void);
void	ft_tolower_test(void);
void	ft_strchr_test(void);
void	ft_strrchr_test(void);
void	ft_strncmp_test(void);
void	ft_memchr_test(void);
void	ft_memcmp_test(void);
void	ft_strnstr_test(void);
void	ft_atoi_test(void);
void	ft_calloc_test(void);
void	ft_strdup_test(void);

/* Part 2 - Additional functions */
void	ft_substr_test(void);
void	ft_strjoin_test(void);
void	ft_strtrim_test(void);
void	ft_split_test(void);
void	ft_itoa_test(void);
void	ft_strmapi_test(void);
void	ft_striteri_test(void);
void	ft_putchar_fd_test(void);
void	ft_putstr_fd_test(void);
void	ft_putendl_fd_test(void);
void	ft_putnbr_fd_test(void);

/* Part 3 - Linked list */
void	ft_lstnew_test(void);
void	ft_lstadd_front_test(void);
void	ft_lstsize_test(void);
void	ft_lstlast_test(void);
void	ft_lstadd_back_test(void);
void	ft_lstdelone_test(void);
void	ft_lstclear_test(void);
void	ft_lstiter_test(void);
void	ft_lstmap_test(void);

/* Part 4 - Linked list utils */
void	ft_free_nodes(t_list *node_a, t_list *node_b, t_list *node_c);
void	ft_create_nodes(t_list **head, t_list **node_a, t_list **node_b,
			t_list **node_c);
void	ft_create_nodes_alloc(t_list **head, t_list **node_a, t_list **node_b,
			t_list **node_c);

#endif
