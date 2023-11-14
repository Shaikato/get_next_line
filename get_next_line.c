/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:45:44 by randre            #+#    #+#             */
/*   Updated: 2023/11/14 15:19:18 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_free(char **memory)
{
	if (*memory != NULL)
	{
		free(*memory);
		*memory = NULL;
	}
	else
		*memory = NULL;
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	i;

	if (!src || n <= 0)
		return (NULL);
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_cut(char **str)
{
	char	*nl_pos;
	char	*res;
	size_t	len;

	if (!str || !*str)
		return (NULL);
	nl_pos = ft_strdup(ft_strchr(*str, '\n'));
	if (nl_pos)
	{
		len = ft_strchr(*str, '\n') - *str;
		res = ft_strndup(*str, len);
		free(*str);
		*str = nl_pos;
	}
	else
	{
		res = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (res);
}

void	loop_get(char *str, int fd, char **memory, int i)
{
	while (i && !ft_strchr(*memory, '\n'))
	{
		str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*str));
		if (!str)
		{
			ft_free(memory);
			return ;
		}
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(memory);
			free(str);
			return ;
		}
		str[i] = 0;
		*memory = ft_strjoin(*memory, str);
		free(str);
	}
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*str;
	int			i;

	i = -1;
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		ft_free(&memory);
		return (NULL);
	}
	str = NULL;
	loop_get(str, fd, &memory, i);
	if (memory == NULL)
		return (NULL);
	str = ft_cut(&memory);
	if (*str == 0 || !str)
	{
		ft_free(&memory);
		free(str);
		return (NULL);
	}
	return (str);
}
