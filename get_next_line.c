/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:36:59 by albokanc          #+#    #+#             */
/*   Updated: 2023/12/04 12:03:28 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char			*buf;
	static char		*stash;
	char			*line;
	int				bytes;

	line = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = 0;
	while ((bytes != 0 && ft_find_n(buf) != 1))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), NULL);
		buf[bytes] = 0;
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (line = ft_getline(stash, line), \
			stash = ft_clean_stash(stash), line);
}

/*#include <stdio.h>

int main()
{
 	int		fd;
 	char 	*str;
 	
 	str = NULL;
 	fd = open("test.txt", O_RDONLY);
 	if (fd == -1)
 		return (1);
 	for (int i = 0; i < 10; i++)
 	{
 		str = get_next_line(fd);
 		printf("%s", str);
		free(str);
 	}
 	printf("%p", str);
	close (fd);
 	return (0);
 }*/
