/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/25 16:37:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	get_paths(char **old_wd, char **cur_wd, char **home_wd, t_env *env)
{
	int	i;

	*old_wd = NULL;
	*cur_wd = NULL;
	*home_wd = NULL;
	i = 0;
	while (env[i])
	{
		if (strncmp("OLDPWD=", env[i], 7))
			*old_wd = &env[i][6];
		if (strncmp("PWD=", env[i], 4))
			*cur_wd = &env[i][3];
		if (strncmp("HOME=", env[i], 5))
			*home_wd = &env[i][4];
		i++;
	}
}

void	exec_cd(char **args, t_env *env_list)
{
	char	*old_wd;
	char	*cur_wd;
	char	*home_wd;

	get_paths(&old_wd, &cur_wd, &home_wd, env_list);
	if (chdir(args[1]) == FAIL)
	{
		write(1, "minishell: cd: ", 15);
		write(1, args[1], ft_strlen(args[1]));
		write(1, ": ", 2);
		perror(NULL);
		return ;
	}
	i = 0;
	return ;
}
