/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:56:09 by bfernan2          #+#    #+#             */
/*   Updated: 2025/08/19 14:41:13 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*read_join(char *buffer, int fd, ssize_t *bytes_read)
{
	char	*temp;
	char	*newbuffer;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	*bytes_read = read(fd, temp, BUFFER_SIZE);
	if (*bytes_read == 0)
	{
		free(temp);
		return (buffer);
	}
	if (*bytes_read < 0)
	{
		free(temp);
		free(buffer);
		return (NULL);
	}
	temp[*bytes_read] = '\0';
	newbuffer = ft_strjoin(buffer, temp);
	free(temp);
	free(buffer);
	return (newbuffer);
}

static char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

static char	*check_empty(char *line, char **buffer)
{
	if (!line || line[0] == '\0')
	{
		free (line);
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytes_read = 1;
	while (!find_nl(buffer))
	{
		buffer = read_join(buffer, fd, &bytes_read);
		if (!buffer)
			return (NULL);
		if (bytes_read == 0)
			break ;
	}
	line = ft_extract_line(buffer);
	buffer = update_buffer(buffer);
	line = check_empty(line, &buffer);
	return (line);
}
