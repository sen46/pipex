/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:44 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/25 15:06:51 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
// #include "get_next_line.h"
// #include "libft.h"
// 
// char	*ft_free_and_strjoin(char *s1, char *s2)
// {
// 	char	*temp;
// 
// 	temp = ft_strjoin(s1, s2);
// 	free(s1);
// 	return (temp);
// }
// 
// char	*ft_next(char *stash)
// {
// 	int		i;
// 	int		j;
// 	char	*new_stash;
// 
// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (!stash[i])
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	new_stash = ft_calloc(ft_strlen(stash) - i, sizeof(char));
// 	if (!new_stash)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (stash[i])
// 		new_stash[j++] = stash[i++];
// 	free(stash);
// 	return (new_stash);
// }
// 
// char	*ft_line(char *stash)
// {
// 	char	*line;
// 	int		i;
// 
// 	i = 0;
// 	if (!stash[i])
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	line = ft_calloc(i + 2, sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] && stash[i] != '\n')
// 	{
// 		line[i] = stash[i];
// 		i++;
// 	}
// 	if (stash[i] == '\n')
// 		line[i++] = '\n';
// 	return (line);
// }
// 
// char	*read_file(int fd, char *stash)
// {
// 	char	buffer[BUFFER_SIZE + 1];
// 	int		byte_read;
// 
// 	if (!stash)
// 		stash = ft_calloc(1, sizeof(char));
// 	if (!stash)
// 		return (NULL);
// 	byte_read = 1;
// 	while (byte_read > 0)
// 	{
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(stash);
// 			return (NULL);
// 		}
// 		buffer[byte_read] = '\0';
// 		stash = ft_free_and_strjoin(stash, buffer);
// 		if (!stash)
// 			return (NULL);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	return (stash);
// }
// 
// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*line;
// 
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	stash = read_file(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	line = ft_line(stash);
// 	stash = ft_next(stash);
// 	return (line);
// }
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:14:52 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/12 19:35:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_free_and_strjoin(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free_and_strjoin(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
