/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:40:50 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/31 18:58:31 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	unlink_node(t_node *tmp, t_env *env_list)
{
	if (tmp->prev != NULL && tmp->next != NULL)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	else if (tmp->prev == NULL && tmp->next == NULL)
	{
		env_list->head = NULL;
		env_list->tail = NULL;
	}
	else if (tmp->prev == NULL)
	{
		env_list->head = tmp->next;
		tmp->next->prev = NULL;
	}
	else
	{
		env_list->tail = tmp->prev;
		tmp->prev->next = NULL;
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
