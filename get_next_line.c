/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:10 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/08 21:34:06 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_line(char *string, int *count)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i++;
	line = my_calloc (i + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = string[j];
		j++;
	}
	*count = i;
	return (line);
}

char	*create_str(int fd, char *string)
{
	int		byte_count;
	char	*tempo;
	char	*temp;

	byte_count = 0;
	while (!my_strchr(string, '\n'))
	{
		tempo = (char *)my_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (tempo == NULL)
			return (NULL);
		byte_count = read(fd, tempo, BUFFER_SIZE);
		if (byte_count == -1)
			return (free(tempo), free(string), NULL);
		if (byte_count == 0)
			return (free(tempo), string);
		if (!string)
			string = my_calloc(1, 1);
		temp = my_strjoin(string, tempo);
		if (!temp)
			return (free(string), NULL);
		free(string);
		string = temp;
		free(tempo);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char		*string;
	char			*new_l;
	int				count;
	char			*temp;

	count = 0;
	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	string = create_str(fd, string);
	if (!string)
		return (free(string), string = NULL, NULL);
	new_l = put_line(string, &count);
	temp = my_substr(string, count, my_strlen(string));
	free(string);
	string = temp;
	if (my_strlen(new_l) == 0)
	{
		if (temp)
		{
			free(temp);
			string = NULL;
		}
		return (free(new_l), NULL);
	}
	return (new_l);
}
