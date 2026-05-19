/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:34:05 by xalves            #+#    #+#             */
/*   Updated: 2025/06/04 11:39:28 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}
/*
My function flow:

	Before: NULL <- [A] <-> [B] <-> [C] -> NULL

	new->next = *lst;
	→ [D].next = [A]

	new->prev = NULL;
	→ [D].prev = NULL (it's the new head)

	(*lst)->prev = new; || -> sets 'old head node' prev to 'new node'
	→ [A].prev = [D]

	*lst = new;
	→ Head pointer now points to [D]

	After: NULL <- [D] <-> [A] <-> [B] <-> [C] -> NULL
*/
/*
void	print_list(t_list *head)
{
	printf("List (forward): ");
	while (head)
	{
		printf("%s ", (char *)head->content);
		head = head->next;
	}
	printf("\n");
}
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	head = NULL;
	node1 = ft_lstnew("Steel");
	node2 = ft_lstnew(" && ");
	node3 = ft_lstnew("Flint");
	ft_lstadd_front(&head, node1); // List: Steel
	ft_lstadd_front(&head, node2); // List: && -> Steel
	ft_lstadd_front(&head, node3); // List: Flint -> &&
	print_list(head);
	// Optional: free memory
	free(node1);
	free(node2);
	return (0);
}
 */
