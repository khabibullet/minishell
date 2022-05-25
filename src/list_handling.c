/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:10:52 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 15:28:32 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

/**
	"init_env_list" initializes default list elements
**/
void	init_env_list(t_env *env)
{
	env->size = 0;
	env->head = NULL;
	env->tail = NULL;
}

/**
	"add_new_env_line" allocates and links new list node and frees input "key" and
	"value" pointers
**/
void	add_new_env_node(t_env *env_list, char *key, char *value)
{
	char	*new_key;
	char	*new_value;
	t_node	*new_node;

	new_key = ft_strdup(key);
	new_value = ft_strdup(value);
	new_node = malloc(sizeof(*new_node));
	new_node->key = new_key;
	new_node->value = new_value;
	new_node->next = NULL;
	if (env_list->size == EMPTY)
	{
		env_list->head = new_node;
		env_list->tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = env_list->tail;
		env_list->tail->next = new_node;
		env_list->tail = new_node;
	}
	env_list->size++;
	free(key);
	free(value);
}

/**
	"copy_env" creates list structure from strings array, setting "key" and "value"
	fields of each list node to substrings of each input string delimeted by '=',
	returns list structure
**/
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
		add_new_env_node(&env_list, tmp[KEY], tmp[VALUE]);
		free(tmp);
		i++;
	}
	return (env_list);
}

/**
	"find_node_by_key" searches for node in list, which "key" field corresponds
	to "key" argument string, and returns pointer to that node or returns NULL if
	there is no such key in list
**/
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

/**
	"destroy_env_list" frees memory allocated for t_env list
**/
void	destroy_env_list(t_env *env_list)
{
	t_node	*node_to_free;
	t_node	*tmp_node;

	tmp_node = env_list->head;
	while (tmp_node)
	{
		node_to_free = tmp_node;
		tmp_node = tmp_node->next;
		free(node_to_free->key);
		free(node_to_free->value);
		free(node_to_free);
	}
}
