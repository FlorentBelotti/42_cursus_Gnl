/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:58 by fbelotti          #+#    #+#             */
/*   Updated: 2023/11/10 15:17:32 by fbelotti         ###   ########.fr       */
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

typedef struct s_list {
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	*create_list(t_list **list, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		search_for_newline(t_list *list);
void	print_next_line(t_list *list);
t_list	*ft_lstnew(char *content, int char_read);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	print_list(t_list *list);
t_list	*ft_lstlast(t_list *lst);
int	find_content_len(t_list *list);

#endif
