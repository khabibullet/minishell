/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:04:43 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 17:05:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	exec_builtin(char **args, t_env *env_list)
{
	char	buf[1000];

	if (ft_strcmp(args[0], "echo") == EQUAL)
		exec_echo(args);
	else if (ft_strcmp(args[0], "cd") == EQUAL)
		exec_cd(args, env);
	else if (ft_strcmp(args[0], "pwd") == EQUAL)
		printf("%s", getcwd(buf, 1000));
	else if (ft_strcmp(args[0], "export") == EQUAL)
		exec_export(args, env);
	else if (ft_strcmp(args[0], "unset") == EQUAL)
		exec_unset(args, env);
	else if (ft_strcmp(args[0], "env") == EQUAL)
		exec_env(args, env);
	else if (ft_strcmp(args[0], "exit") == EQUAL)
		exit(EXIT_SUCCESS);
	else
		return ;
}
