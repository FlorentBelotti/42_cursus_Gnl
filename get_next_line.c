/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/15 17:30:35 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	create_list(&list, fd);
	if (!list)
		return (NULL);
	put_line(list, &line);
	clean_list(&list);
	if (line[0] == '\0')
	{
		free_list(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	clean_list(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!list || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) *
				((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_list(*list);
	*list = clean_node;
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		char_read;

	char_read = 0;
	while (!search_for_newline(*list) && char_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		char_read = (int)read(fd, buffer, BUFFER_SIZE + 1);
		if ((!list && char_read == 0) || char_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_to_list(list, buffer, char_read);
		free(buffer);
	}
}

static void	add_to_list(t_list **list, char *buffer, int char_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (char_read + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < char_read)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new_node;
}

void	put_line(t_list *list, char **line)
{
	int		j;
	int		i;

	if (!list)
		return ;
	list = list;
	malloc_of_line(line, list);
	if (!line)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}
