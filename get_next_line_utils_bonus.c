/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:04 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/17 17:05:08 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	search_for_newline(t_list *list)
{
	int		i;
	t_list	*last;

	if (list == NULL)
		return (0);
	last = ft_lstlast(list);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

t_list	*ft_lstlast(t_list *list)
{
	t_list	*current;

	current = list;
	if (current == NULL)
		return (current);
	while (current->next)
		current = current->next;
	return (current);
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

void	malloc_of_line(char **line, t_list *list)
{
	int		newline_index;
	int		i;

	newline_index = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\n' && list->content[i])
		{
			i++;
			newline_index++;
		}
		if (list->content[i] == '\n')
			newline_index++;
		list = list->next;
	}
	*line = malloc(sizeof(char) * (newline_index + 1));
}
