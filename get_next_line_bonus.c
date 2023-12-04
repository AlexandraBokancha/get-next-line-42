/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:13:32 by albokanc          #+#    #+#             */
/*   Updated: 2023/12/04 16:36:58 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (stash[i])
	{	
		new[j++] = stash[i];
		i++;
	}
	new[j] = '\0';
	return (free(stash), new);
}

int	ft_find_n(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

char	*ft_getline(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * i + 2);
	else
		line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	while (j <= i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*stash[1024];
	char			*line;
	int				bytes;

	line = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = 0;
	while ((bytes != 0 && ft_find_n(buff) != 1))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), NULL);
		buff[bytes] = 0;
		stash[fd] = ft_strjoin(stash[fd], buff);
	}
	free(buff);
	return (line = ft_getline(stash[fd], line), \
			stash[fd] = ft_clean_stash(stash[fd]), line);
}
