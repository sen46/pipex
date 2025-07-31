/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:45:05 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/08 14:34:20 by ssawa            ###   ########.fr       */
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
	int		**pipes;

	// initializeで設定
	char	**paths;      // 解析済みのPATH
	char	***cmd_args;  // コマンド引数配列、何番目もコマンド、コマンドの文字列の集合をダブルポインタで管理する
						   // コマンドはオプションがついている場合文字列の集合に分ける必要があるため
	int		cmd_count;
	char	**cmd_path;
	// char	*cmd1_path;   // 1つ目のコマンドのフルパス
	// char	*cmd2_path;   // 2つ目のコマンドのフルパス

}	t_pipex;
#endif
