/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:04 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/13 16:03:49 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function that create a new node contening the content passes. */

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

/* Function that take the created node and put it at the end of the list. */

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!lst)
		lst = new;
	else
	{
		last = ft_lstlast(lst);
		last->next = new;
	}
}

/* Function that find the last node. */

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* Function that find the total len of the line. */

int	find_content_len(t_list *list)
{
	t_list	*temp;
	int		i;
	int		total_len;

	if (!list)
		return (0);
	total_len = 0;
	temp = list;
	if (!temp)
		return (0);
	while (temp)
	{
		i = 0;
		if (temp->content)
		{
			while (temp->content[i] != '\0')
			{
				i++;
				total_len++;
			}
		}
		temp = temp->next;
	}
	total_len++;
	return (total_len);
}

/* Function that search for a newline into every node of the linked list. */

int	search_for_newline(t_list *list)
{
	int		i;
	t_list *temp;

	temp = list;
	i = 0;
	if (!list)
		return(0);
	while (temp)
	{
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				return (i);
			}
			i++;
		}
		temp = temp->next;
		i = 0;
	}
	return (0);
}
