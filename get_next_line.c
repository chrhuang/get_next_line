/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:06:02 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/27 16:36:10 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h> //A surppimer

static t_list	*get_file(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	*list = tmp;
	return (tmp);
}

static unsigned int	search_end(char *str)
{
	unsigned int	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
		i = i + 1;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*curr;
	char			buff[BUFF_SIZE + 1];
	int				len;
	unsigned int	end;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
	{
		return (-1);
	}	
	curr = get_file(&list, fd);
	len = 0;
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		if ((curr->content = ft_strjoin(curr->content, buff)) == NULL)
			return (-1);
		if (ft_strchr(curr->content, '\n'))
			break ;
	}
	end = search_end(curr->content);
	*line = curr->content;
	(*line)[end] = '\0';
	curr->content = curr->content + end + 1;
	if (len != BUFF_SIZE && end == 0 && ft_strlen(curr->content) == 0)
		return (0);
	return (1);
}
