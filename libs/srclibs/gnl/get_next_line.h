/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:19:21 by jnaftana          #+#    #+#             */
/*   Updated: 2022/01/23 12:19:21 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

// DELETE THISSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t		ft_strlen(const char *str);
void		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
void		ft_strappend(char **s1, const char *s2, size_t len_s2);
void		ft_strlcat(char *dest, const char *src, size_t size);

char	*get_next_line(int fd);
int append_last_read(char **line, char **prev_read);
void read_from_fd(int fd, char **line, char **prev_read, int *eof);
char	*ft_strdup(const char *src);

#endif