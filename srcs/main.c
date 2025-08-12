/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:34:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 22:07:11 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (valid(argc, argv, &pipex))
		return (1);
	initialize(argc, argv, envp, &pipex);
	execute_commands(&pipex, envp);
	free_all(&pipex);
	return (0);
}
