/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:12:58 by aldgonza          #+#    #+#             */
/*   Updated: 2022/10/13 14:43:46 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src [count] != '\0' && count < (size - 1))
	{
		dest[count] = src [count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	strl;

	i = 0;
	strl = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((1 + strl) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	ft_strlcpy((char *)&newstr[i], s2, ft_strlen(s2) + 1);
	return (newstr);
}

int	ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == (char ) ch)
			return (i);
		i++;
	}
	if (str[ft_strlen(str)] == (char ) ch)
		return (i);
	return (-1);
}

char	*ft_cut_buff(char *buffer)
{
	char	*temp;
	int		i;

	i = ft_strchr(buffer, '\n');
	if (i == ft_strlen(buffer) - 1)
		return (NULL);
	if (i == -1)
		return (NULL);
	temp = malloc(ft_strlen(buffer) - i);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	temp[0] = '\0';
	temp = ft_substr(buffer, i + 1, ft_strlen(buffer));
	free(buffer);
	return(temp);
}
char	*ft_substr(char *s, int start, int len)
{
	char	*newstr;

	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - (int)start;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s[start], len + 1);
	free(newstr);
	return (newstr);
}
