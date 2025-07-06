/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:36:25 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/06 22:27:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "struct.h"

# define PIPES 1
# define HERE_DOC 2
int	valid(int ac, char **av, t_file *fd);

#endif
