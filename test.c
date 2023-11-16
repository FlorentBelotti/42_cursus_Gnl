void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t			i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < count)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	s_len = strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}



void	clean_list_v2(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	last = ft_lstlast(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;

	char *tmp_content = ft_substr((last->content), i , (strlen(last->content) - i) + 1);
	free (last->content);
	last->content = tmp_content;

}

void	clean_list_v3(t_list **list)
{
	t_list	*last;
	char	*next_line;
	int		i;
	int		j;
	int		line_len;

	i = 0;
	j = 0;
	if (list == NULL)
		return ;
	last = ft_lstlast(*list);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	line_len = ft_strlen(last->content) - i + 1 ;
	next_line = malloc(sizeof(char) * line_len);
	if (!next_line)
		return ;
	while (last->content[i])
		next_line[j++] = last->content[i++];
	next_line[j] = '\0';
	free_list(*list);
	add_to_list(list, next_line, line_len);
	free(next_line);
}
