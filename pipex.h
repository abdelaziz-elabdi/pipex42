/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:03:16 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/02/26 11:57:05 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

void	pipex(char *av[], char *env[]);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*cherch_path(char *envr[]);
void	jus_error(char *s);
char	*path(char *path[], char *cmds[]);
void	exec_comand(char *envr[], char *cmd);
void	second_comand(char *av[], char *env[], int *fd);
void	first_comand(char *av[], char *env[], int *fd);
char	*cherch_path(char *envr[]);
char	*ft_strchr(const char *s, int c);

#endif