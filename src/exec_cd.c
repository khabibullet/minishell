/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/31 18:58:02 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	cd_home_env(char **oldpwd, char **pwd, char **home)
{
	if (home == NULL)
		printf("minishell: cd: HOME not set\n");
	else if (chdir(*home) == FAIL)
		ft_perror(3, "minishell: cd: ", *home, ": ");
	else
		refresh_wd_paths(oldpwd, pwd);
}

static void	cd_tilda(char **oldpwd, char **pwd, char **home, char *path)
{
	char	*buf;

	if (ft_strcmp(path, "~") == EQUAL)
	{
		if (home == NULL || ft_strcmp(*home, "") != EQUAL)
		{
			if (home == NULL)
				buf = getenv("HOME");
			else
				buf = *home;
			if (chdir(buf) == FAIL)
				ft_perror(3, "minishell: cd: ", buf, ": ");
			else
				refresh_wd_paths(oldpwd, pwd);
		}
	}
	else
	{
		buf = ft_strjoin("/Users/", path + 1);
		if (chdir(buf) == FAIL)
			ft_perror(3, "minishell: cd: ", buf, ": ");
		else
			refresh_wd_paths(oldpwd, pwd);
		free(buf);
	}
}

static void	cd_dash(char **oldpwd, char **pwd, char **home, char *opt)
{
	if (ft_strcmp(opt, "-") == EQUAL)
	{
		if (oldpwd == NULL)
			printf("minishell: cd: OLDPWD not set\n");
		else
		{
			if (chdir(*oldpwd) == FAIL)
				ft_perror(3, "minishell: cd: ", *oldpwd, ": ");
			else
				refresh_wd_paths(oldpwd, pwd);
		}
	}
	if (ft_strcmp(opt, "--") == EQUAL)
	{
		if (home == NULL)
			printf("minishell: cd: HOME not set\n");
		else
		{
			if (chdir(*home) == FAIL)
				ft_perror(3, "minishell: cd: ", *home, ": ");
			else
				refresh_wd_paths(oldpwd, pwd);
		}
	}
}

static void	cd_path(char **oldpwd, char **pwd, char *path)
{
	if (chdir(path) == FAIL)
		ft_perror(3, "minishell: cd: ", path, ": ");
	else
		refresh_wd_paths(oldpwd, pwd);
}

void	exec_cd(char **args, t_env *env_list)
{
	char	**oldpwd;
	char	**pwd;
	char	**home;

	get_paths(&oldpwd, &pwd, &home, env_list);
	if (args[1] == NULL || ft_strcmp(args[1], "~-") == EQUAL)
		cd_home_env(oldpwd, pwd, home);
	else if (args[1][0] == '~')
		cd_tilda(oldpwd, pwd, home, args[1]);
	else if (args[1][0] == '-')
		cd_dash(oldpwd, pwd, home, args[1]);
	else
		cd_path(oldpwd, pwd, args[1]);
}
