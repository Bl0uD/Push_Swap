/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:18:50 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/23 13:46:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del)
		return ;
	while (tmp != NULL)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
}
