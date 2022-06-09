/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:24 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/09 15:41:33 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	env_list;
	char	**env_arr;

	(void)argc;
	(void)argv;
	env_list = copy_env(env);
	env_arr = list_to_array(&env_list);
	printf("\n");
	while (*env_arr)
	{
		printf("%s\n", *env_arr);
		env_arr++;
	}
	printf("\n");
	destroy_env_list(&env_list);
	return (0);
}
