/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/06 22:29:52 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*char_read;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &char_read, 0) < 0)
		return (NULL);
}

// function that calls create_list must call for the new_node to be the
// created node.

void	*create_list(t_list **list, int fd)
{
	t_list	new_node;
	char	*buffer;
	int		char_read;

	char_read = 0;
	new_node = malloc(size_of(t_list));
	if (!new_node)
		return (NULL);
	char_read = read(fd, buffer, BUFFER_SIZE);
	if (!char_read)
	{
		free(buffer);
		return ;
	}
	buffer[char_read] = '\0';
	new_node->content = buffer;
	new_node->next = NULL;
}

int	search_for_newline(t_list *list)
{
	int		i;

	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
