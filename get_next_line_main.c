/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:23:24 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/15 17:21:03 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

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
