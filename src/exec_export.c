/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:45:33 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/01 15:58:50 by anemesis         ###   ########.fr       */
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

static void	print_error(char **pair, char *arg)
{
	printf("minishell: export: `%s': not a valid identifier\n", arg);
	free(pair[KEY]);
	if (pair[VALUE] != NULL)
		free(pair[VALUE]);
}

static void	handle_key_n_value(char **pair, t_env *env_list, char *arg)
{
	t_node	*tmp;

	if (is_all_chars_valid(pair[KEY]) == INVALID)
		print_error(pair, arg);
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

static void	append_line(char **pair, t_env *env_list, char *arg)
{
	int		end;
	char	*buf;
	t_node	*tmp;

	end = ft_strlen(pair[KEY]) - 1;
	if ((is_all_chars_valid(pair[KEY]) == INVALID && pair[KEY][end] != '+')
		|| pair[KEY][0] == '+')
		print_error(pair, arg);
	else if (pair[VALUE] == NULL)
		free(pair[KEY]);
	else
	{
		pair[KEY][end] = '\0';
		tmp = find_node_by_key(pair[KEY], env_list);
		if (tmp != NULL)
		{
			buf = tmp->value;
			tmp->value = ft_strjoin(buf, pair[VALUE]);
			free(buf);
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
		if (ft_strchr(pair[0], '+') != NULL)
			append_line(pair, env_list, args[i]);
		else
			handle_key_n_value(pair, env_list, args[i]);
		free(pair);
		i++;
	}
}
