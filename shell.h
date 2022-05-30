/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:12 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/30 17:04:49 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# define KEY 0
# define VALUE 1
# define EQUAL 0
# define EMPTY 0
# define FAIL -1
# define NEWLINEFLAG 1
# define INVALID 1

typedef struct t_node
{
	char			*key;
	char			*value;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct t_env
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_env;

void	destroy_env_list(t_env *env_list);
void	add_new_env_node(t_env *env_list, char *key, char *value);
t_env	copy_env(char **env);
t_node	*find_node_by_key(char *key, t_env *env_list);

void	exec_builtins(char **args, t_env *env_list);
void	exec_echo(char **args);
void	exec_env(char **args, t_env *env_list);
void	exec_unset(char **args, t_env *env_list);
void	exec_export(char **args, t_env *env_list);
void	exec_cd(char **args, t_env *env_list);

int		is_all_chars_valid(char *str);
char	**split_by_first_occur(char	const	*s, char c);
void	ft_perror(int count, ...);
#endif
