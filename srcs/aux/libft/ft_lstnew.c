/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:38:17 by xalves            #+#    #+#             */
/*   Updated: 2025/06/04 11:26:45 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alocates size of LinkedList
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	new_node ->prev = NULL;
	return (new_node);
}
/*
int	main(void)
{
	char	*text;
	t_list	*node;

	text = "aaa";
	node = ft_lstnew(text);
	if (node)
	{
		printf("Node content: %s\n", (char *)node->content);
		printf("Next: %p\n", (void *)node->next);
		printf("Prev: %p\n", (void *)node->prev);
	}
	else
		printf("Node creation failed.\n");
	free(node);
	return (0);
} */
