/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/09 17:45:08 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*char_read;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &char_read, 0) < 0)
		return (NULL);
	// Create the list until the first '\n'
	create_list(&list, fd);
	print_list(list);
	return (NULL);
}

// function that calls create_list must call for the new_node to be the
// created node.

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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = temp;
	}
}

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
				return (1);
			}
			i++;
		}
		temp = temp->next;
		i = 0;
	}
	return (0);
}
void	print_list(t_list *list)
{
	int	i;
	t_list	*temp;

	temp = list;
	if (!list)
		return ;
	while(temp)
	{
		i = 0;
		while (temp->content[i])
		{
			write(1, (char *)&(temp->content)[i], 1);
			i++;
		}
		temp = temp->next;
	}
}

// main test

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	//char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		perror("Error returning file");
	get_next_line(fd);
	close (fd);
}
