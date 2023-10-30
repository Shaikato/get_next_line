/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:24:11 by randre            #+#    #+#             */
/*   Updated: 2023/10/30 11:41:50 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
unsigned int	ft_strlen(const char *str);
char			*get_next_line(int fd);

#endif