/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:24 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 17:05:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	env_list;
	char *args[] = {"export", "arg=2", NULL};
	// int	i;
	(void)argc;
	(void)argv;
	// (void)env;
	init_env_list(&env_list);
	env_list = copy_env(env);
	printf("\n\n\n");
	exec_env(env_list);
	printf("\n\n\n");
	exec_export(args, &env_list);
	exec_env(env_list);
	destroy_env_list(&env_list);
	return (0);
}
