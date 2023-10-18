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

char	*ft_cut(char *str)
{
	char	*tr_str;
	char	*start;

	tr_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	start = tr_str;
	while(*(str - 1) != '\n' && *str)
	{
		*tr_str = *str;
		tr_str++;
		str++;
	}
	*tr_str = 0;
	return (start); 
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*tr_str;
	char		*str;
	int			i;

	str = (char *)malloc(BUFFER_SIZE + 1 * sizeof(*str));
	if (!str)
		return (NULL);
	i = 1;
	while(i && !ft_strchr(str, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		str[i] = 0;
		memory = ft_strjoin(memory, str);
	}
	tr_str = ft_strdup(memory);
	memory = ft_strchr(memory, '\n');
	return (ft_cut(tr_str));
}
