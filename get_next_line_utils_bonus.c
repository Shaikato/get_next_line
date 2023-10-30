/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:39:58 by randre            #+#    #+#             */
/*   Updated: 2023/10/30 12:40:00 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned char	ch;

	if (!str || str == NULL)
		return (NULL);
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

	if (!s)
		return (NULL);
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

char	*ft_strjoin2(char *s1, char *s2, char *str)
{
	char	*start;
	char	*s_start;

	start = str;
	s_start = s1;
	if (s1)
	{
		while (*s1)
		{
			*str = *s1;
			str++;
			s1++;
		}
	}
	free(s_start);
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = 0;
	return (start);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		str = malloc((ft_strlen(s2) + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (ft_strjoin2(s1, s2, str));
}
