/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:56:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/04 14:23:17 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	// Add nodes to the list
	ft_lstadd_front(&head, ft_lstnew("Node 5"));
	ft_lstadd_front(&head, ft_lstnew("Node 4"));
	ft_lstadd_front(&head, ft_lstnew("Node 3"));
	ft_lstadd_front(&head, ft_lstnew("Node 2"));
	ft_lstadd_front(&head, ft_lstnew("Node 1"));

	// Print the size of the list
	printf("List size: %d\n", ft_lstsize(head));
	// Optional: free memory
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}*/
