/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:39:11 by randre            #+#    #+#             */
/*   Updated: 2023/10/31 05:05:49 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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