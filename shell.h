/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:12 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 21:37:58 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define KEY 0
# define VALUE 1
# define EQUAL 0
# define EMPTY 0
# define FAIL 1
# define NEWLINE 1
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

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char	const	*s, char c);
char	*ft_strdup(const char *s1);

void	init_env_list(t_env *env);
void	add_new_env_line(t_env *env_list, char *key, char *value);
t_env	copy_env(char **env);
t_node	*find_node_by_key(char *key, t_env *env_list);
void	unlink_node(t_node *tmp, t_env *env_list);

void	exec_echo(char **args);
void	exec_env(t_env env_list);
void	exec_unset(char **args, t_env *env_list);

int		is_all_chars_valid(char *str);

#endif
