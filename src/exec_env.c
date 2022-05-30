/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:38:57 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/30 15:24:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

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
