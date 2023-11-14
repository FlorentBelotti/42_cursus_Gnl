/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/14 12:09:09 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*list;
	int				i;
	char			*next_node;
	char			*char_read;
	char			*line;

	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &char_read, 0) < 0)
		return (NULL);

	create_list(&list, fd);

	/* line = put_line(list);

	if (BUFFER_SIZE > 1)
	{
		next_node = next_node_content(list);
		while (next_node[i])
			i++;
	}
	else
		next_node = NULL;
	ft_lstclear(list);
	ft_lstadd_back(list, ft_lstnew((void *)next_node, i + 1));
	print_list(list);
	write (1, "\n", 1); */
	print_list (list);
	return (line);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	lst = NULL;
}

/* Function that search_for_newline, and if not create new node that is put
at the end of the string with the content of buffer. */

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		char_read;

	char_read = 0;
	while (!search_for_newline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE + 1);
		if ((!list && char_read == 0) || char_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_lstadd_back(*list, ft_lstnew((void *)buffer, char_read));
		free(buffer);
	}
	return ;
}

/* Return a string with the content of my linked list. */

char	*put_line(t_list *list)
{
	int		i;
	int		j;
	int		newline_index;
	char	*line;
	t_list	*temp;

	j = 0;
	temp = list;
	newline_index = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\n')
		{
			i++;
			newline_index++;
		}
		temp = temp->next;
	}
	line = malloc(sizeof(char) * (newline_index + 2));
	if (!line)
		return (NULL);
	temp = list;
	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\n' && temp->content[i])
		{
			line[j] = temp->content[i];
			i++;
			j++;
		}
		if (temp->content[i] == '\n')
		{
			line[j] = temp->content[i];
			break ;
		}
		temp = temp->next;
	}
	return (line);
}

/* Create a node with the content of the last node of my linked list. */

char	*next_node_content(t_list *lst)
{
	int		newline_index;
	int		m_len;
	int		i;
	char	*next_line;
	t_list	*temp;

	temp = lst;
	if (!temp)
		write (1, "8", 1);
	m_len = 0;
	i = 0;
	newline_index = 0;
	newline_index = search_for_newline(temp) + 1;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				while (temp->content[m_len] != '\0')
					m_len++;
				break ;
			}
			i++;
		}
		if (m_len == 0)
			temp = temp->next;
		else
			break ;
	}
	next_line = malloc (sizeof(char) * (m_len + 1));
	i = 0;
	if (temp->content[newline_index] == '\0')
	{
		next_line[i] = '\0';
		return (next_line);
	}
	while (temp->content[newline_index] != '\0')
	{
		next_line[i] = temp->content[newline_index];
		newline_index++;
		i++;
	}
	next_line[i] = '\0';
	if (next_line[i] == '\0')
		printf("Il y a un 0\n");
	return (next_line);
}


	// Go to temp->content[i] == '\n'
