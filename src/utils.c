/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:29:10 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 13:49:34 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	is_all_chars_valid(char *str)
{
	while (*str)
	{
		if (((int)*str < 65 && (int)*str > 32)
			|| ((int)*str < 95 && (int)*str > 90)
			|| ((int)*str < 128 && (int)*str > 122)
			|| ((int)*str == 96))
			return (1);
		str++;
	}
	return (0);
}

char	**split_by_first_occur(char	const	*s, char c)
{
	char	**all_split;
	char	**pair;

	pair = malloc(sizeof(*pair) * 2);
	if (!pair)
		exit(EXIT_FAILURE);
	all_split = ft_split(s, c);
	pair[KEY] = all_split[0];
	pair[VALUE] = all_split[1];
	if (ft_strchr(s, c))
	{
		free(pair[VALUE]);
		pair[VALUE] = ft_strdup(ft_strchr(s, c) + 1);
	}
	free(all_split);
	return (pair);
}

void	export_declare(t_env env_list)
{
	t_node	*tmp_node;

	tmp_node = env_list.head;
	while (tmp_node)
	{
		printf("declare -x %s=%s\n", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->next;
	}
}

void	unlink_node(t_node *tmp, t_env *env_list)
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
