/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/05/30 15:24:45 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

static void	get_paths(char ***oldpwd, char ***pwd, char ***home, t_env *list)
{
	t_node	*tmp;

	tmp = find_node_by_key("OLDPWD", list);
	*oldpwd = NULL;
	if (tmp)
		*oldpwd = &tmp->value;
	tmp = find_node_by_key("PWD", list);
	*pwd = NULL;
	if (tmp)
		*pwd = &tmp->value;
	tmp = find_node_by_key("HOME", list);
	*home = NULL;
	if (tmp)
		*home = &tmp->value;
}

static void	cd_home_env(char **oldpwd, char **pwd, char **home)
{
	if (home == NULL)
		printf("minishell: cd: HOME not set\n");
	else if (chdir(*home) == FAIL)
		ft_perror(3, "minishell: cd: ", *home, ": ");
	else
	{
		free(*oldpwd);
		*oldpwd = *pwd;
		if (*oldpwd == NULL)
			*oldpwd = ft_strdup("");
		else
			*pwd = getcwd(NULL, 0);
	}
}

static void	change_wds(char **oldpwd, char **pwd, char *old_ch, char *pwd_ch)
{
	if (old_ch != NULL)
	{
		free(*oldpwd);
		*oldpwd = old_ch;
	}
	if (pwd_ch != NULL)
	{
		// free(*pwd);
		*pwd = pwd_ch;
	}
}

static void	cd_tilda(char **oldpwd, char **pwd, char **home)
{
	char	*buf;

	if (home == NULL || ft_strcmp(*home, "") != EQUAL)
	{
		if (home == NULL)
			buf = getenv("HOME");
		else
			buf = *home;
		if (chdir(buf) == FAIL)
		{
			ft_perror(3, "minishell: cd: ", buf, ": ");
			return ;
		}
	}
	if (pwd != NULL)
	{
		if (oldpwd != NULL)
			change_wds(oldpwd, pwd, *pwd, getcwd(NULL, 0));
		else
			change_wds(oldpwd, pwd, NULL, getcwd(NULL, 0));
	}
	else if (oldpwd != NULL)
		change_wds(oldpwd, pwd, ft_strdup(""), NULL);
	else
		return ;
}

void	exec_cd(char **args, t_env *env_list)
{
	char	**oldpwd;
	char	**pwd;
	char	**home;

	get_paths(&oldpwd, &pwd, &home, env_list);
	if (args[1] == NULL || ft_strcmp(args[1], "~-") == EQUAL)
		cd_home_env(oldpwd, pwd, home);
	else if (ft_strcmp(args[1], "~") == EQUAL)
		cd_tilda(oldpwd, pwd, home);
	return ;
}
