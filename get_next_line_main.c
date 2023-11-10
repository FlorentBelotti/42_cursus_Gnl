/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:23:24 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:43 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
