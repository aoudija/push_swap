/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:11:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 10:00:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_optimize(const char *s, unsigned int start, char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < (ft_strlen(s) - start))
		sub = malloc(len + 1);
	else
		sub = malloc(ft_strlen(s) - start + 1);
	if (sub == NULL)
		return (NULL);
	return (ft_optimize(s, start, sub, len));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	char	*sj;
	int		d;
	int		s;

	if (!s1 || !s2)
		return (NULL);
	d = ft_strlen(s1);
	s = ft_strlen(s2);
	len = d + s;
	sj = (char *)malloc(len + 1);
	if (sj == NULL)
		return (NULL);
	ft_strlcpy(sj, s1, d + 1);
	ft_strlcat(sj, s2, len + 1);
	free(s1);
	return (sj);
}
