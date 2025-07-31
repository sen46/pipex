/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:34:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/07 19:16:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (valid(argc, argv, &pipex))
	{
		return (1);
	}
	initialize(argc, argv, envp, &pipex);
	/*
	for (int i = 0; pipex.cmd_args[i]; i++)
	{
		for (int j = 0; pipex.cmd_args[i][j]; j++)
		{
			printf("%s\n", pipex.cmd_args[i][j]);
		}
	}
	for (int i = 0; pipex.paths[i]; i++)
	{
		printf("%s\n", pipex.paths[i]);
	}
	write(1, "ok\n", 3);
	*/
	// main_process()
	// EXIT()
	return (0);
}
