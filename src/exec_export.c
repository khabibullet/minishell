/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:45:33 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 16:53:28 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	export_declare(t_env env_list)
{
	t_node	*tmp_node;

	tmp_node = env_list.head;
	while (tmp_node)
	{
		printf("declare -x %s=%s\n", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->next;
	}
}

static void	handle_key_n_value(char **pair, t_env *env_list)
{
	t_node	*tmp;

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
}

void	exec_export(char **args, t_env *env_list)
{
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
		handle_key_n_value(pair, env_list);
		free(pair);
		i++;
	}
}
