/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:36:25 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 14:33:09 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "struct.h"
# include <stdio.h>
# include <sys/wait.h>

# define PIPES 1
# define HERE_DOC 2

int		valid(int argc, char **argv, t_pipex *fd);
char	**find_path_from_envp(char **envp);
void	free_char_deg2(char **str);
void	free_char_deg3(char ***str);
void	free_all(t_pipex *pipex);
void	close_all_pipes(int cmd_count, int **pipes);
int		initialize(int argc, char **argv, char **envp, t_pipex *pipex);
void	get_cmd_path(t_pipex *pipex);
void	execute_commands(t_pipex *pipex, char **envp);
char	*ft_strjoin3(char *str1, char *str2, char *str3);
void	free_str(char *str);

#endif
