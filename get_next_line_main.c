/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:23:24 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/14 18:40:53 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

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
			if (temp->content[i] == '\0')
				printf("Il y a un 0\n");
			else
				write(1, (char *)&(temp->content)[i], 1);
			i++;
		}
		temp = temp->next;
	}
}

void	print_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		write(1, &line[i], 1);
		i++;
	}
}

int	main(void)
{
	int		fd;
	char	*line;
	//char *line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		perror("Error returning file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
	close (fd);
	return (0);
}
