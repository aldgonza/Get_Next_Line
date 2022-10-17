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

////////////////////////////////////////STRLEN
int	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

////////////////////////////////////////STRLCPY
int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (0);
	while (src [count] != '\0' && count < (size - 1))
	{
		dest[count] = src [count];
		count++;
	}
	dest[count] = '\0';
	return (0);
}

////////////////////////////////////////STRJOIN
char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		size1;
	int		size2;

	i = 0;
	size1 = 0;
	if (s1)
		size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	newstr = (char *)malloc((1 + (size1 + size2)) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (size1 > 0 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	ft_strlcpy((char *)&newstr[i], s2, size2 + 1);
	return (newstr);
}

////////////////////////////////////////STRNCHR
int	ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char ) ch)
			return (i);
		i++;
	}
	if (str && str[i] == (char ) ch)
		return (i);
	return (-1);
}

////////////////////////////////////////SUBSTR
char	*ft_substr(char *s, int start, int len)
{
	char	*newstr;
	int		i;

	i = ft_strlen(s);
	if (start > i)
		start = i;
	if (len > i - start)
		len = i - (int)start;
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s[start], len + 1);
	return (newstr);
}
