/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:24 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/30 17:11:03 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	env_list;

	(void)argc;
	(void)argv;
	env_list = copy_env(env);
	printf("\n");
	// exec_builtins((char *[]){"pwd", NULL}, &env_list);
	// exec_builtins((char *[]){"cd", "~", NULL}, &env_list);
	// exec_builtins((char *[]){"pwd", NULL}, &env_list);
	exec_builtins((char *[]){"env", "PWDasda=adassd", NULL}, &env_list);
	// exec_builtins((char *[]){"export", NULL}, &env_list);
	destroy_env_list(&env_list);
	printf("\n");
	return (0);
}
