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
#include <stdio.h>

char	*ft_add_buff(char *buffer, int fd)
{
	int		read_bytes;
	char	read_array[BUFFER_SIZE + 1];

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
	}
	while((read_bytes = read(fd, read_array, BUFFER_SIZE)) > 0)
	{
		read_array[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, read_array);
		if (ft_strchr(buffer, '\n') != -1)
			return (buffer);
	}
	if (read_bytes == 0 && ft_strlen(buffer) == 0)
		return(NULL);
	free(buffer);
	return (buffer);
}

char	*ft_add_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	if(!buffer)
		return(NULL);
	if ((len = (ft_strchr(buffer, '\n'))) == -1)
		len = ft_strlen(buffer);
	line = malloc(len + 1 * sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	line[len + 1] = '\0';
	while (i < (len + 1))
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) == -1))
		return (NULL);
	if (!buffer || (buffer && (ft_strchr(buffer, '\n') == -1)))
		buffer = ft_add_buff(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_add_line(buffer);
	buffer = ft_cut_buff(buffer);
	return (line);
}
int	main()
{
	int		fdd;
	char	*str;
	int		i;

	i = 0;
	fdd = open("text.txt", O_RDONLY);
	while (str)
	{
		i++;
		str = get_next_line(fdd);
		printf("RETURN %i :\n[%s]\n=========================\n",i , str);
		if (!str)
			printf("\nES NUUUUUULL CABRON!!!!\n");
	}
	close(fdd);
	return (0);
}