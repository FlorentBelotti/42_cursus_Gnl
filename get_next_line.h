/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:58 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/15 17:23:05 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list {
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	put_line(t_list *list, char **line);
int		search_for_newline(t_list *list);
int		ft_strlen(const char *str);
void	clean_list(t_list **list);
void	create_list(t_list **list, int fd);
void	malloc_of_line(char **line, t_list *list);
void	free_list(t_list *list);
static void	add_to_list(t_list **list, char *buffer, int char_read);
int		main(void);
t_list	*ft_lstlast(t_list *stash);

#endif
