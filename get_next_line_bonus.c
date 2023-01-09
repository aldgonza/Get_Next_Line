/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by aldgonza          #+#    #+#             */
/*   Updated: 2022/10/11 18:51:38 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

////////////////////////////////////////FREE
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

////////////////////////////////////////ADD_BUFF
char	*ft_add_buff(char *buffer, int fd)
{
	int		read_bytes;
	char	read_array[BUFFER_SIZE + 1];

	read_bytes = read(fd, read_array, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		read_array[read_bytes] = '\0';
		buffer = ft_free(buffer, read_array);
		if (ft_strchr(buffer, '\n') != -1)
			return (buffer);
		read_bytes = read(fd, read_array, BUFFER_SIZE);
	}
	if (read_bytes == 0 && !buffer)
		return (0);
	return (buffer);
}

////////////////////////////////////////ADD_LINE
char	*ft_add_line(char *buffer)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_strchr(buffer, '\n');
	if (!buffer)
		return (0);
	if (len == -1)
		len = ft_strlen(buffer);
	ret = malloc((len + 2) * sizeof(char));
	if (!ret)
		return (0);
	ret[len + 1] = '\0';
	while (i < (len + 1))
	{
		ret[i] = buffer[i];
		i++;
	}
	return (ret);
}

////////////////////////////////////////CUT_BUFF
char	*ft_cut_buff(char *buffer)
{
	char	*temp;
	int		i;

	i = ft_strchr(buffer, '\n');
	if (i == ft_strlen(buffer) - 1)
	{
		free(buffer);
		return (0);
	}
	if (i == -1)
	{
		free(buffer);
		return (0);
	}
	temp = ft_substr(buffer, i + 1, ft_strlen(buffer));
	free(buffer);
	return (temp);
}

////////////////////////////////////////GNL :)
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) == -1))
		return (0);
	if (!buffer[fd] || (buffer[fd] && (ft_strchr(buffer[fd], '\n') == -1)))
		buffer[fd] = ft_add_buff(buffer[fd], fd);
	if (!buffer[fd])
		return (0);
	line = ft_add_line(buffer[fd]);
	buffer[fd] = ft_cut_buff(buffer[fd]);
	return (line);
}
