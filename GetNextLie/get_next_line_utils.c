/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:06:24 by echernys          #+#    #+#             */
/*   Updated: 2024/10/18 16:38:47 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	unsigned int		i;
	char	*s2;
	
	s2 = malloc(sizeof(char) * ft_strlen(s1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i++])
		newstr[i] = s1[i];
	i = 0;
	while (s2[i++])
		newstr[ft_strlen(s1) + i] = s2[i]; 
	newstr[ft_strlen(s1) + i] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)ft_strlen(s) <= len)
	{
		newstr = malloc(sizeof(char));
		if (newstr)
			newstr[0] = '\0';
		return (newstr);
	}
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (len > i++)
		newstr[i] = s[i + start];
	newstr[i] = '\0';
	return (newstr);
}
