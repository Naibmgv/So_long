/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:02:05 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/05 10:45:50 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static char	*set_left(char *line)
{
	int		i;
	char	*left;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	if (!left)
		return (NULL);
	return (left);
}

char	*set_line(const char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	new_line = ft_substr(line, 0, i + 1);
	if (!new_line || *new_line == '\0')
		return (NULL);
	return (new_line);
}

static char	*ft_find_line(int fd, char *buffer, char *left)
{
	char	*temp;
	int		i;

	i = 2;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (left);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!left)
			left = ft_strdup("");
		temp = left;
		left = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;
	char		*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left);
		buffer = NULL;
		left = NULL;
		return (NULL);
	}
	line = ft_find_line(fd, buffer, left);
	free(buffer);
	if (!line)
		return (NULL);
	temp = set_line(line);
	left = set_left(line);
	free (line);
	return (temp);
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;
// 	fd = open("get_next_line.h", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free (line);
// 	}
// }