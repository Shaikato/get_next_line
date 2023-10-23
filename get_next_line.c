/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:45:44 by randre            #+#    #+#             */
/*   Updated: 2023/10/18 17:45:44 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (*str && *(str - 1) != '\n')
	{
		i++;
		str++;
	}
	return (i);
}

char    *ft_strndup(const char *src, size_t n)
{
    char    *dup;
    size_t  i;

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

char    *ft_cut(char **str)
{
    char    *nl_pos;
    char    *res;
    size_t  len;

    if (!str || !*str)
        return (NULL);
    nl_pos = ft_strchr(*str, '\n');
    if (nl_pos)
    {
        len = nl_pos - *str;
        res = ft_strndup(*str, len);
        *str = nl_pos + 1;
    }
    else
    {
        res = ft_strdup(*str);
        *str += ft_strlen(*str);
    }
    return (res);
}

void	ft_free(char *memory, char *str)
{
	if (memory)
		free(memory);
	if (str)
		free(str);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*tr_str;
	char		*str;
	int			i;
	static int	eof;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || eof == 1)
		return (NULL);
	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*str));
	if (!str)
	{
		ft_free(memory, str);
		return (NULL);
	}
	i = 1;
	while(i && !ft_strchr(str, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		str[i] = 0;
		memory = ft_strjoin(memory, str);
	}
	if (i == 0)
		eof = 1;
	str = ft_cut(&memory);
	printf("Mem = %s\n", memory);
	return (str);
}
