/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 15:30:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	exec_echo(char **args)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (ft_strcmp(args[1], "-n") != EQUAL)
		flag = NEWLINE;
	else
		i++;
	while (args[i])
	{
		if (ft_strcmp(args[i], "-n") != EQUAL)
			printf("%s ", args[i]);
		i++;
	}
	if (flag == NEWLINE)
		printf("\n");
	else
		printf("\b");
}

void	exec_env(t_env env_list)
{
	t_node	*tmp_node;

	tmp_node = env_list.head;
	while (tmp_node)
	{
		printf("%s=%s\n", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->next;
	}
}

void	exec_unset(char **args, t_env *env_list)
{
	t_node	*tmp;
	int		i;

	i = 1;
	while (args[i])
	{
		if (is_all_chars_valid(args[i]) == INVALID)
			printf("minishell: unset: `%s': not a valid identifier\n", args[i]);
		else
		{
			tmp = find_node_by_key(args[i], env_list);
			if (tmp != NULL)
			{
				free(tmp->key);
				free(tmp->value);
				unlink_node(tmp, env_list);
				free(tmp);
				env_list->size--;
			}
		}
		i++;
	}
}

void	exec_export(char **args, t_env *env_list)
{
	t_node	*tmp;
	int		i;
	char	**pair;

	if (args[1] == NULL)
	{
		export_declare(*env_list);
		return ;
	}
	i = 1;
	while (args[i])
	{
		pair = split_by_first_occur(args[i], '=');
		if (is_all_chars_valid(pair[KEY]) == INVALID)
		{
			printf("minishell: export: `%s': not a valid identifier\n",
				pair[KEY]);
			free(pair[KEY]);
			if (pair[VALUE] != NULL)
				free(pair[VALUE]);
		}
		else if (pair[VALUE] == NULL)
			free(pair[KEY]);
		else
		{
			tmp = find_node_by_key(pair[KEY], env_list);
			if (tmp != NULL)
			{
				free(tmp->value);
				tmp->value = pair[VALUE];
			}
			else
				add_new_env_node(env_list, pair[KEY], pair[VALUE]);
		}
		free(pair);
		i++;
	}
}
