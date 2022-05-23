/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:29:24 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/23 21:49:43 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

// void	get_paths(char **old_wd, **char **cur_wd, char **home_wd, char **env)
// {
// 	int	i;

// 	*old_wd = NULL;
// 	*cur_wd = NULL;
// 	*home_wd = NULL;
// 	i = 0;
// 	while (env[i])
// 	{
// 		if (strncmp("OLDPWD=", env[i], 7))
// 			*old_wd = &env[i][6];
// 		if (strncmp("PWD=", env[i], 4))
// 			*cur_wd = &env[i][3];
// 		if (strncmp("HOME=", env[i], 5)) 
// 			*home_wd = &env[i][4];
// 		i++;
// 	}
// }

// void	exec_chdir(char **args, char **env)
// {
// 	char	*old_wd;
// 	char	*cur_wd;
// 	char	*home_wd;

// 	get_paths(&old_wd, &cur_wd, &home_wd, env);
// 	if (chdir(args[1]) == FAIL)
// 	{
// 		write(1, "minishell: cd: ", 15);
// 		write(1, args[1], ft_strlen(args[1]));
// 		write(1, ": ", 2);
// 		perror(NULL);
// 		return ;
// 	}
// 	i = 0;
// 	return ;
// }

// void	exec_export(char **args, t_env *env_list)
// {
	
// }

void	exec_builtin(char **args, char **env)
{
	// char	buf[1000];

	(void)env;
	if (ft_strcmp(args[0], "echo") == EQUAL)
		exec_echo(args);
	// else if (ft_strcmp(args[0], "cd") == EQUAL)
	// 	exec_chdir(args, env);
	// else if (ft_strcmp(args[0], "pwd") == EQUAL)
	// 	printf("%s", getcwd(buf, 1000));
	// else if (ft_strcmp(args[0], "export") == EQUAL)
	// 	exec_export(args, env);
	// else if (ft_strcmp(args[0], "unset") == EQUAL)
	// 	exec_unset(args, env);
	// else if (ft_strcmp(args[0], "env") == EQUAL)
	// 	exec_env(args, env);
	else if (ft_strcmp(args[0], "exit") == EQUAL)
		exit(0);
	else
		return ;
}

int	main(int argc, char **argv, char **env)
{
	t_env	env_list;
	char *args[] = {"unset", "TMPDIR", "=", NULL};
	(void)argc;
	(void)argv;
	// (void)env;
	// (void)args;
	init_env_list(&env_list);
	env_list = copy_env(env);
	exec_unset(args, &env_list);
	// exec_env(env_list);
	return (0);
}
