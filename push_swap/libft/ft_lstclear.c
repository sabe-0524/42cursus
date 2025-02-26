/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:52:46 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:25:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_sub;
	t_list	*next_node;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	lst_sub = *lst;
	while (lst_sub != NULL)
	{
		next_node = lst_sub->next;
		del(lst_sub->content);
		free(lst_sub);
		lst_sub = next_node;
	}
	*lst = NULL;
}
