/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:45:05 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 18:52:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <sys/types.h>
typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		type;
	char	**paths;
	char	***cmd_args;
	int		cmd_count;
	char	**cmd_path;
	int		status;
}	t_pipex;

typedef struct s_fd
{
	int		pipe[2];
	int		prev;
	pid_t	last_pid;
}	t_fd;

#endif
