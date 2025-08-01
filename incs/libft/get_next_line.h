/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:02:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/15 14:37:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

/*
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);
*/

#endif
