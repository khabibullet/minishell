/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:10:52 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 19:03:13 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	init_env_list(t_env *env)
{
	env->size = 0;
	env->head = NULL;
	env->tail = env->head;
}

void	add_new_env_line(t_env *env_list, char *key, char *value)
{
	char	*new_key;
	char	*new_value;
	t_node	*new_line;

	new_key = ft_strdup(key);
	new_value = ft_strdup(value);
	new_line = malloc(sizeof(*new_line));
	new_line->key = new_key;
	new_line->value = new_value;
	new_line->next = NULL;
	if (env_list->size == EMPTY)
	{
		env_list->head = new_line;
		env_list->tail = new_line;
		new_line->prev = NULL;
	}
	else
	{
		new_line->prev = env_list->tail;
		env_list->tail->next = new_line;
		env_list->tail = new_line;
	}
	env_list->size++;
	free(key);
	free(value);
}

t_env	copy_env(char **env)
{
	t_env	env_list;
	int		i;
	char	**tmp;

	init_env_list(&env_list);
	i = 0;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		add_new_env_line(&env_list, tmp[KEY], tmp[VALUE]);
		free(tmp);
		i++;
	}
	return (env_list);
}

t_node	*find_node_by_key(char *key, t_env *env_list)
{
	t_node	*tmp;

	tmp = env_list->head;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == EQUAL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
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
