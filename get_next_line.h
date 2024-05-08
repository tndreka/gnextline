/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:13:48 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/08 21:32:51 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

void	*my_calloc(size_t count, size_t size);
char	*my_strchr(const char *s, int c);
char	*my_substr(char *s, unsigned int start, size_t len);
char	*my_strjoin(char *s1, char *s2);
size_t	my_strlen(char *s);
char	*get_next_line(int fd);
char	*create_str(int fd, char *string);
char	*put_line(char *string, int *count);

#endif