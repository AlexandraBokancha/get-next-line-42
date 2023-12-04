/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:13 by albokanc          #+#    #+#             */
/*   Updated: 2023/12/04 11:48:18 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcpy(char *s1, char *s2, char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	while (buff[j])
	{
		s2[i++] = buff[j];
		j++;
	}
	free(s1);
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*news;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!buff || !stash)
		return (NULL);
	news = malloc(((ft_strlen(stash) + ft_strlen(buff) + 1) * sizeof(char)));
	if (!news)
		return (NULL);
	return (news = ft_strlcpy(stash, news, buff));
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}
