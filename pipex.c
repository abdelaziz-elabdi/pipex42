/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:52:54 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/02/26 11:55:09 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_comand(char *envr[], char *cmd)
{
	char	**check_comand;
	char	**check_path;
	char	*pa_co;
	char	*cherch;

	check_comand = ft_split(cmd, ' ');
	if (!check_comand)
		jus_error("problem in command!\n");
	cherch = cherch_path(envr);
	check_path = ft_split(cherch, ':');
	if (!check_path)
		jus_error("problem in path!\n");
	pa_co = path(check_path, check_comand);
	if (pa_co)
	{
		if (execve(pa_co, check_comand, envr) == -1)
			jus_error("problem execve!\n");
	}
	jus_error("command not found!\n");
}

void	second_comand(char *av[], char *env[], int *fd)
{
	int	file2;

	file2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	close (fd[1]);
	if (file2 == -1)
	{
		close (fd[1]);
		close (fd[0]);
		jus_error("problem open file2!\n");
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		jus_error("problem dup2");
	}
	if (dup2(file2, STDOUT_FILENO) == -1)
	{
		jus_error("problem dup2");
	}
	close(fd[0]);
	close(file2);
	exec_comand(env, av[3]);
}

void	first_comand(char *av[], char *env[], int *fd)
{
	int	file1;

	file1 = open(av[1], O_RDONLY, 0777);
	close(fd[0]);
	if (file1 == -1)
	{
		close (fd[1]);
		close (fd[0]);
		jus_error("problem open file1!\n");
	}
	if (dup2(file1, STDIN_FILENO) == -1)
		jus_error("problem dup2");
	close(file1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		jus_error("problem dup2");
	close(fd[1]);
	exec_comand(env, av[2]);
}

void	pipex(char *av[], char *env[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (!env)
		jus_error("problem in env!\n");
	if (pipe(fd) == -1)
		jus_error("problem pipe\n");
	pid1 = fork();
	if (pid1 == -1)
		jus_error("problem first fork!\n");
	if (pid1 == 0)
		first_comand(av, env, fd);
	pid2 = fork();
	if (pid2 == -1)
		jus_error("problem second fork!\n");
	if (pid2 == 0)
		second_comand(av, env, fd);
	close (fd[1]);
	close (fd[0]);
	wait(NULL);
	wait(NULL);
}
