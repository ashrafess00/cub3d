/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:27:12 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 14:51:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*new_node;
	void	*new_content;

	tmp = lst;
	list = NULL;
	while (tmp != NULL)
	{
		new_content = f(tmp->content);
		new_node = ft_lstnew(new_content);
		ft_lstadd_back(&list, new_node);
		tmp = tmp->next;
	}
	(void) del;
	return (list);
}
