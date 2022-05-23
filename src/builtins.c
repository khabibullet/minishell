/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 21:52:10 by anemesis         ###   ########.fr       */
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
	t_node	*tmp_line;

	tmp_line = env_list.head;
	while (tmp_line)
	{
		printf("%s=%s\n", tmp_line->key, tmp_line->value);
		tmp_line = tmp_line->next;
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
