/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:29:39 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/30 21:19:18 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_get(char *s1, char *s2)
{
	int		len;
	char	*sj;
	int		d;
	int		s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	d = ft_strlen(s1);
	s = ft_strlen(s2);
	len = d + s;
	sj = malloc(len + 1);
	if (sj == NULL)
		return (NULL);
	ft_strlcpy(sj, s1, d + 1);
	ft_strlcat(sj, s2, len + 1);
	free(s1);
	return (sj);
}

char	*ft_read(int fd, char *buffer, char *t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			if (t)
				free(t);
			return (NULL);
		}
		buffer[i] = 0;
		t = ft_strjoin_get(t, buffer);
		if (!t)
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[0] == 0)
	{
		free(t);
		return (NULL);
	}
	return (t);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*t;
	char		*line;
	char		*tmp;

	buffer = malloc(1 + 1);
	if (!buffer)
		return (NULL);
	t = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t);
	tmp = t;
	t = ft_substr(t, ft_strlen(line), ft_strlen(t) - ft_strlen(line) + 1);
	free(tmp);
	return (line);
}
