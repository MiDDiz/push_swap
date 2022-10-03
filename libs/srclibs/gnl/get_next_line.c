/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:19:10 by jnaftana          #+#    #+#             */
/*   Updated: 2022/01/23 12:19:10 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
/*
	This function returns a null terminated line without newline characters (´\n´)

	append_last_read returns 1 if it appended every char of prev_read
	and we still have to read more characters from fd
	and returns 0 if we have to flush the new line but there still are more 
	characters to return in prev_read.
*/

char	*get_next_line(int fd)
{
	static char	*prev_read;
	static int eof;
	char *line;

	eof = 0;
	line = NULL;
	if (fd < 0)
		return (line);
	if(append_last_read(&line, &prev_read) && !eof)
	{
		//printf("1\n");
		read_from_fd(fd, &line, &prev_read, &eof);
		//printf("2\n");
	}
	//printf("3\n");
	return (line);
}

int append_last_read(char **line, char **prev_read)
{
	char	*new_line;
	char	*swap;

	if (*prev_read  == NULL || *prev_read[0] == '\0')
	{
		//printf(" - Prev read is NULL\n");
		return (1);
	}
	//printf(" - Prev read is: %s\n", *prev_read);
	new_line = ft_strchr(*prev_read, '\n');
	if (new_line != NULL)
	{
		//printf(" - Found new line \n");
		ft_strappend(line, *prev_read, (size_t)(new_line - *(prev_read) + 1));
		swap = ft_strdup(new_line + 1);
		free(*prev_read);
		*prev_read = swap;
		return (0);
	}
	//printf(" - NOT Found new line \n");
	ft_strappend(line, *prev_read, ft_strlen(*prev_read));
	free(*prev_read);
	*prev_read = NULL;
	return (1);
}

void read_from_fd(int fd, char **line, char **prev_read, int *eof)
{
	char	*buff;
	int		num_c;
	char	*new_line;


	buff = (char *)malloc(BUFFER_SIZE + 1);
	//printf(" - Malloced buffer\n");
	num_c = read(fd, buff, BUFFER_SIZE);
	while(num_c > 0)
	{
		//printf(" - Read done\n");
		buff[num_c] = '\0';
		
		//printf(" - Null terminated BUFFER: %s Numc : %ld\n", buff, num_c);
		new_line = ft_strchr((char *)buff, '\n');

		
		if (new_line != NULL)
		{
			
			ft_strappend(line, buff, new_line - buff + 1);
			ft_strappend(prev_read, new_line + 1, ft_strlen(new_line));
			free(buff);
			return ;
		}
		
		ft_strappend(line, buff, num_c);
		num_c = read(fd, buff, BUFFER_SIZE);
		//printf("New num_c: %ld\nsleep\n", num_c);
		//sleep(1);
	}
	*eof = 1;
	free(buff);
}

char	*ft_strdup(const char *src)
{
	char	*output_str;
	int		i;

	output_str = (char *) malloc(sizeof (*src) * (ft_strlen(src) + 1));
	if (!output_str)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output_str[i] = src[i];
		i++;
	}
	output_str[i] = '\0';
	return (output_str);
}