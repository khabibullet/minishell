/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:38:57 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/30 17:08:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static int	check_env_errors(char **args, t_env *env_list)
{
	if (ft_strcmp(args[1], "PWD") == EQUAL
		|| ft_strcmp(args[1], "LOGNAME") == EQUAL)
	{
		printf("%s\n", getenv(args[1]));
		return (1);
	}
	else if (args[1][0] == '=')
	{
		printf("env: %s: Invalid argument\n", args[1]);
		return (1);
	}
	else if (ft_strchr(args[1], '=') == NULL)
	{
		printf("env: %s: No such file or directory\n", args[1]);
		return (1);
	}
	else
		exec_export(args, env_list);
	return (0);
}

void	exec_env(char **args, t_env *env_list)
{
	t_node	*tmp_node;

	if (args[1] != NULL && check_env_errors(args, env_list) == 1)
		return ;
	tmp_node = env_list->head;
	while (tmp_node)
	{
		printf("%s=%s\n", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->next;
	}
}
