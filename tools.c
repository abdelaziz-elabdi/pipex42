/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:04 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/02/26 09:45:45 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cherch_path(char *envr[])
{
	char	*path;

	if (!envr)
		return (NULL);
	while (*envr)
	{
		if (ft_strncmp("PATH", *envr, 4) == 0)
		{
			path = *envr + 5;
			return (path);
		}
		envr++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	while (d != s[i])
	{
		if (s[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *)(s + i));
}

char	*path(char *path[], char *cmds[])
{
	char	*cmd_acces;
	char	*tmp;

	if (ft_strchr(cmds[0], '/') != 0)
		return (cmds[0]);
	if (ft_strchr(cmds[0], '.') != 0)
		return (cmds[0] + 2);
	while (*path)
	{
		tmp = ft_strjoin("/", cmds[0]);
		cmd_acces = ft_strjoin(*path, tmp);
		free(tmp);
		if (access(cmd_acces, F_OK) == 0)
		{
			return (cmd_acces);
		}
		free(cmd_acces);
		path++;
	}
	return (NULL);
}

void	jus_error(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return ;
	while (s[j])
	{
		write(2, &s[j++], 1);
	}
	exit(EXIT_FAILURE);
}
