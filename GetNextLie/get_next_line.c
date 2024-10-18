/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:06:29 by echernys          #+#    #+#             */
/*   Updated: 2024/10/18 16:34:05 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while(s[i] != (unsigned char)c || s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return (s + i);
	return (NULL);
}

char	*set_stash(char *line_buffer)
{
	char	*stash;
	ssize_t	i;
	
	i = 0;
	while (line_buffer[i] != '\n' || line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	stash = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*stash == '\0')
	{
		free (stash);
		stash = NULL;
	}
	stash[i + 1] = '\0';
	return (stash);
	
}

char	*fill_buffer(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_lus;
	char	*temp;

	bytes_lus = 1;
	while (bytes_lus > 0)
	{
		bytes_lus = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lus == -1)
		{
			free (stash);
			return (NULL);
		}
		else if (bytes_lus == 0)
			break ;
		buffer[bytes_lus] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line_buffer;
	char			*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0 ,0) < 0)
	{
		free (buffer);
		free (stash);
		buffer = NULL;
		stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line_buffer = fill_buffer(fd, stash, buffer);
	free (buffer);
	if (!line_buffer)
		return (NULL);
	stash = set_stash(line_buffer);
	return (line_buffer);
}
