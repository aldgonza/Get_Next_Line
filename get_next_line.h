/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:09:32 by aldgonza          #+#    #+#             */
/*   Updated: 2022/10/13 14:40:20 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

char	*get_next_line(int fd);
int     ft_strlen(const char *str);
size_t  ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(const char *str, int ch);
char	*ft_add_buff(char *buffer, int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_add_line(char *buffer);
char    *ft_cut_buff(char *buffer);
char	*ft_free(char *buffer, char *buf);

#endif
