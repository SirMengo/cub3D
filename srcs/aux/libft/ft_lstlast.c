/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:36:47 by xalves            #+#    #+#             */
/*   Updated: 2025/06/04 15:13:14 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
// while (lst->next) = Do While 'next node' != NULL
/*
int	main(void)
{
	t_list *head = NULL;

	// Create a list: Node 1 -> Node 2 -> Node 3
	ft_lstadd_front(&head, ft_lstnew("Node 4"));
	ft_lstadd_front(&head, ft_lstnew("Node 3"));
	ft_lstadd_front(&head, ft_lstnew("Node 2"));
	ft_lstadd_front(&head, ft_lstnew("Node 1"));

	// Get the last node
	t_list *last = ft_lstlast(head);

	// Print the content of the last node
	if (last)
		printf("Last node content: %s\n", (char *)last->content);
	else
		printf("List is empty.\n");

	// Free memory
	t_list *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
} */
