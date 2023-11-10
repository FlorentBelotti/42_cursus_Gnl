/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/10 17:11:59 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*char_read;
	char			*line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &char_read, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	line = put_line(list);

	//create a node base on the rest of the last node
	//clear the list

	print_list(list);
	return (NULL);
}

/* Function that search_for_newline, and if not create new node that is put
at the end of the string with the content of buffer. */

void	*create_list(t_list **list, int fd)
{
	char	*buffer;
	int		char_read;

	char_read = 0;
	while (!search_for_newline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*list && char_read == 0) || char_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		ft_lstadd_back(list, ft_lstnew((void *)buffer, char_read));
		free(buffer);
	}
	return (0);
}

char	*put_line(t_list *list)
{
	int		total_len;
	int		i;
	int		j;
	char	*line;
	t_list	*temp;

	total_len = find_content_len(temp);
	line = malloc(sizeof(char) * total_len + 1);
	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i] && temp->content[i] != '\n')
		{
			line[j] = temp->content[i];
			i++;
			j++;
		}
		while (temp->content[i] == '\n')
		{
			line[j] = '\n';
			j++;
		}
		temp = temp->next;
	}
	return (line);
}

t_list	*create_next_list(t_list *lst)
{
	t_list	*temp;
	t_list	*new_node;
	char	*next_content;
	int		total_len;
	int		content_len;

	content_len = 0;
	temp = lst;
	ft_lstlast(temp);
	if (!temp)
		return (NULL);
	total_len = find_content_len(temp);
	while (temp->content[total_len] != '\n')
	{
		total_len--;
		content_len++;
	}
	next_content = malloc(sizeof(char) * content_len + 1);
	if (!next_content)
		return(NULL);

