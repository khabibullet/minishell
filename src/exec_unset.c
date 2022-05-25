/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:40:50 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 16:57:28 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

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
