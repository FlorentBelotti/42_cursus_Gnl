/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:04 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/09 17:39:07 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content, int char_read)
{
	t_list	*lst;
	int i;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	i = 0;
	lst->content = malloc(sizeof(char) * (char_read + 1));
	while (content[i] && i < char_read)
	{
		lst->content[i] = content[i];
		i++;
	}
	lst->content[i] = '\0';
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

t_list	*ft_lstget_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
