/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:49:37 by xalves            #+#    #+#             */
/*   Updated: 2025/06/06 15:53:45 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del_one(t_list **head, t_list *node, void (*del)(void *))
{
	if (!*head || !head || !node || !del)
		return ;
	if (*head == node)
		*head = node->next;
	if (node->prev)
		(node->prev)->next = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	del(node->content);
	free(node);
}
/*
if (!*head || !head || !node || !del)
Checks:
!*head -> checks if the list is Null
!head -> checks if the pointer to the list head itself is NULL.
!node -> node to delete is Null
!del -> function del is Null


if (*head == node)
		*head = node->next;
if the node to delete is = head,
then the next node will be the new head
 */
/*
void	print_list(t_list *lst)
{
	printf("List: ");
	while (lst)
	{
		printf("[%s] ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head;
	t_list	*node_to_delete;
	t_list	*tmp;

	head = NULL;
	// Create and add nodes
	ft_lstadd_back(&head, ft_lstnew(strdup("One")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Two")));
	node_to_delete = ft_lstnew(strdup("Three"));
	ft_lstadd_back(&head, node_to_delete);
	ft_lstadd_back(&head, ft_lstnew(strdup("Four")));
	printf("Before deletion:\n");
	print_list(head);
	// Delete node "Three"
	ft_lstdelone(&head, node_to_delete, del_content);
	printf("After deletion:\n");
	print_list(head);
	// Cleanup rest of list
	while (head)
	{
		tmp = head;
		head = head->next;
		del_content(tmp->content);
		free(tmp);
	}
	return (0);
} */
