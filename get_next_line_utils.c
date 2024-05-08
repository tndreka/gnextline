/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:32 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/08 21:36:14 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*my_calloc(size_t count, size_t size)
{
	unsigned char	*cptr;
	size_t			i;

	cptr = malloc(count * size);
	if (!cptr)
		return (NULL);
	i = -1;
	while (++i < (count * size))
		cptr[i] = '\0';
	return ((void *)cptr);
}

size_t	my_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s || !*s)
		return (0);
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*my_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*my_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)my_calloc(len + 1, sizeof(char));
	if (!s || !new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < my_strlen(s) && j < len)
		new_str[j++] = s[i++];
	return (new_str);
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	j = 0;
	i = 0;
	len = my_strlen(s1) + my_strlen(s2);
	res = (char *)my_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	return (res);
}
