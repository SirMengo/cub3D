/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:56:59 by xalves            #+#    #+#             */
/*   Updated: 2025/06/06 17:15:28 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
Function name ft_lstiter

Prototype void ft_lstiter(t_list *lst, void (*f)(void *));

Turn in files -

Parameters:
lst: The address of a pointer to a node.
f: The address of the function to apply to each node’s content.
Return value None

External functs. None

Description Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node.
*/
/*
#include <ctype.h>
#include <string.h>
void print_uppercase(void *content)
{
	char *str = (char *)content;
	int i = 0;

	while (str[i])
	{
		putchar(toupper(str[i]));
		i++;
	}
	putchar('\n');
}

int main(void)
{
	t_list *node1 = ft_lstnew(strdup("hello"));
	t_list *node2 = ft_lstnew(strdup("world"));
	t_list *node3 = ft_lstnew(strdup("minishell"));

	// Linking the nodes
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;

	// Apply print_uppercase to each node's content
	ft_lstiter(node1, print_uppercase);

	// Cleanup
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);

	return 0;
} */
