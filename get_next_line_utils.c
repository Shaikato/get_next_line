/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:52 by randre            #+#    #+#             */
/*   Updated: 2023/10/18 18:23:52 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*str)
		if (*str++ == ch)
			return ((char *)str);
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s)
	{
		*str = *s;
		s++;
		str++;
	}
	*str = 0;
	return (start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	if (!s1)
		str = malloc((ft_strlen(s2) + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	if (s1)
		while (*s1)
		{
			*str = *s1;
			str++;
			s1++;
		}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = 0;
	return (start);
}