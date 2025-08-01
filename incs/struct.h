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

/*
typedef struct s_file
{
	int	f1;
	int	f2;
	int	type;
	char	*path;
} t_file;
*/

typedef struct s_pipex
{
	// validateで設定
	int		infile_fd;
	int		outfile_fd;
	int		type;
	// int		**pipes;

	// initializeで設定
	char	**paths;      // 解析済みのPATH
	char	***cmd_args;  // コマンド引数配列、何番目もコマンド、コマンドの文字列の集合をダブルポインタで管理する
						   // コマンドはオプションがついている場合文字列の集合に分ける必要があるため
	// コマンド数
	int		cmd_count;
	// フルパス
	char	**cmd_path;
}	t_pipex;

typedef struct s_fd
{
	int	pipe[2];
	int	prev;
} t_fd;
#endif
