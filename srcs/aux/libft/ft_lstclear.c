/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:03:57 by xalves            #+#    #+#             */
/*   Updated: 2025/06/06 15:54:09 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst || !lst || !del)
		return ;
	if ((*lst)->prev)
		((*lst)->prev)->next = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
/*
void	del_content(void *content)
{
	free(content);
}

#include <string.h>

int	main(void)
{
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 1")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 2")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Node 3")));
	printf("Before clear:\n");
	print_list(head);
	ft_lstclear(&head, del_content);
	printf("After clear:\n");
	print_list(head);
	return (0);
}*/
