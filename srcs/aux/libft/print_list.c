/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:54:29 by xalves            #+#    #+#             */
/*   Updated: 2025/06/06 12:54:34 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
