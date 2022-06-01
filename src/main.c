/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:24 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/31 18:58:09 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	env_list;
	char	**pair;

	(void)argc;
	(void)argv;
	env_list = copy_env(env);
	printf("\n");
	exec_builtins((char *[]){"cd", "~", NULL}, &env_list);
	exec_builtins((char *[]){"cd", "42cursus", NULL}, &env_list);
	exec_builtins((char *[]){"pwd", NULL}, &env_list);
	exec_builtins((char *[]){"cd", "~", NULL}, &env_list);
	exec_builtins((char *[]){"pwd", NULL}, &env_list);
	destroy_env_list(&env_list);
	printf("\n");
	pair = split_by_first_occur("abd", '=');
	printf("%d \n", is_all_chars_valid("+"));
	printf("\n");
	return (0);
}
